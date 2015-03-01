package eu.powet.groundcopter.utils;

import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;

import org.osmdroid.util.GeoPoint;

import android.app.Activity;
import android.content.Context;
import android.os.Environment;
import android.util.Log;
import android.widget.Toast;

import com.mavlink.messages.IMAVLinkMessage;
import com.mavlink.messages.common.msg_attitude;
import com.mavlink.messages.common.msg_command_ack;
import com.mavlink.messages.common.msg_gps_raw_int;
import com.mavlink.messages.common.msg_heartbeat;
import com.mavlink.messages.common.msg_mission_ack;
import com.mavlink.messages.common.msg_mission_count;
import com.mavlink.messages.common.msg_mission_item;
import com.mavlink.messages.common.msg_mission_item_reached;
import com.mavlink.messages.common.msg_mission_request;
import com.mavlink.messages.common.msg_nav_controller_output;
import com.mavlink.messages.common.msg_servo_output_raw;
import com.mavlink.messages.common.msg_sys_status;
import com.mavlink.messages.common.msg_vfr_hud;

import eu.powet.groundcopter.GeoPointMission;
import eu.powet.groundcopter.controller.IController;
import eu.powet.groundcopter.controller.Request;
import eu.powet.groundcopter.events.JMAVLink;
import eu.powet.groundcopter.events.MavLinkEvent;
import eu.powet.groundcopter.events.MavLinkEventListener;
import eu.powet.groundcopter.events.MavlinkEventConnected;
import eu.powet.groundcopter.events.MavlinkEventDisconnected;

public class MavlinkManager {

	protected static final String TAG = null;
	private JMAVLink mavlink;


	public void write_stream(Context context, String data){ 
		FileWriter writer=null;
		try{ 
			String horodatage = android.text.format.DateFormat.format("hh:mm:ss", new java.util.Date()).toString();
			File f = new File(Environment.getExternalStorageDirectory(), "copter.log");
			writer = new FileWriter(f,true);
			writer.write(data+" "+horodatage+"\n");
			writer.flush();
		} 
		catch (Exception e) {       
			Log.e("logging copter",""+e);
		} 
		finally { 
			if(writer !=null){
				try {
					writer.close();
				} catch (IOException e) {
						// ignore
				}
			}
		} 
	}



	public MavlinkManager(final IController kController,final Activity ctx){
		mavlink = new JMAVLink(ctx);
		mavlink.addEventListener(new MavLinkEventListener() {
			@Override
			public void receive(final MavLinkEvent evt, final IMAVLinkMessage msg) 
			{
				//Log.d(TAG,"receive("+msg+")");
				if(msg instanceof msg_vfr_hud){

					msg_vfr_hud t = (msg_vfr_hud)msg;
					kController.handleMessage(Request.UPDATE_HUD_ALTITUDE,t.alt);

					Boolean  record = (Boolean)kController.getMessage(Request.GET_STATUS_LOG);
					if(record){
						write_stream(ctx,t.alt+" alt");
					}
				

				}else if( msg instanceof msg_heartbeat)
				{
					final msg_heartbeat t = (msg_heartbeat)msg;
					
		
					kController.handleMessage(Request.HEARTBEAT);
					
					kController.handleMessage(Request.IS_DISARMED);
					if(t.base_mode == 81)
					{
						kController.handleMessage(Request.IS_DISARMED);
					}else if(t.base_mode == 209)
					{
						kController.handleMessage(Request.IS_ARMED);
					}
				}else if( msg instanceof msg_sys_status)
				{
					msg_sys_status t = (msg_sys_status)msg;
					kController.handleMessage(Request.SYS_STATUS,t);
			

				}else if(msg instanceof msg_attitude){

					msg_attitude t = (msg_attitude)msg;
					System.out.println(t.roll);

					kController.handleMessage(Request.UPDATE_FLIGHTDATA,t);
				
				}else if(msg instanceof msg_mission_count){

					msg_mission_count t = (msg_mission_count)msg;

					for(int i=0;i<t.count;i++)
					{
						msg_mission_request req = new msg_mission_request();
						req.seq = i;
						req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
						req.target_component = 0;
						if(!mavlink.writeMessage(req))
						{
							i--;
						}
					}

				}else if(msg instanceof msg_mission_ack)
				{
					kController.handleMessage(Request.TOAST_MSG,"Mission "+JMAVLink.getMAV_MISSION_RESULT(((msg_mission_ack)msg).type));
					if(((msg_mission_ack)msg).type == JMAVLink.MAV_MISSION_RESULT.MAV_MISSION_ACCEPTED){


						kController.handleMessage(Request.CLEAR_UI_WAYPOINTS);
						kController.handleMessage(Request.UPDATE_MAP);

						kController.handleMessage(Request.READ_WAYPOINTS);
					}

				}else if(msg instanceof msg_mission_request){

					msg_mission_request t  = (msg_mission_request)msg;

					try 
					{
						//System.out.println(t.seq);
						msg_mission_item req = new msg_mission_item();
						req.seq = t.seq;
						req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
						req.target_component = 0;

						req.x =   (float) (kController.getWaypoints().get(t.seq).getLatitudeE6()/1e6);
						req.y =   (float) (kController.getWaypoints().get(t.seq).getLongitudeE6()/1e6);
						req.z = (kController.getWaypoints().get(t.seq).getAltitude());
						req.command = JMAVLink.MAV_CMD.MAV_CMD_NAV_WAYPOINT;
						req.autocontinue = 1;
						req.param1 = 0;
						req.param2 = 0;

						if(mavlink.writeMessage(req))
						{
							Log.d(TAG," Writing  msg_mission_item "+t.seq+"  x= "+req.x+" y="+req.y+" "+req.z+" autocontinue="+req.autocontinue+" command="+req.command+" "+req.param1);
						}else 
						{
							kController.handleMessage(Request.TOAST_MSG,"Request waypoint "+t.seq);
						}
					}catch(Exception e ){
						e.printStackTrace();
						kController.handleMessage(Request.TOAST_MSG,"Error during Write waypoint "+t.seq);
					}
		


				}else if(msg instanceof msg_mission_item_reached)
				{
					msg_mission_item_reached reached  = (msg_mission_item_reached)msg;
					kController.getWaypoints().get(reached.seq).setReached(true);

				}
				else if(msg instanceof msg_mission_item)					
				{
					msg_mission_item t = (msg_mission_item)msg;
					GeoPointMission waypoint = new GeoPointMission(new GeoPoint(t.x, t.y, t.z),t.param2);
					kController.handleMessage(Request.ADD_WAYPOINT, waypoint);
					kController.handleMessage(Request.UPDATE_MAP);
					if(t.seq == 0)
					{
					//	kController.handleMessage(Request.ANIMATE_TO_MAP_WAYPOINT,waypoint);	
					}

				}else if(msg instanceof msg_gps_raw_int)
				{

					final msg_gps_raw_int gps = (msg_gps_raw_int)msg;


					switch(gps.fix_type){
					case 0: 

						kController.handleMessage(Request.UPDATE_HUD_GPSFIX, "no fix");
						break;
					case 1:
						kController.handleMessage(Request.UPDATE_HUD_GPSFIX, "no fix");
						break;

					case 2 :
						kController.handleMessage(Request.UPDATE_HUD_GPSFIX, "2D fix "+gps.satellites_visible);
						break;

					case 3 : 
				
						
						GeoPointMission gPt = new GeoPointMission(new GeoPoint(gps.lat/ 1E7,gps.lon/1E7)); 


						//track.addPoint(gPt);TODO
						kController.handleMessage(Request.ADD_TRACK,gPt);
						kController.handleMessage(Request.SET_DRONE_POSITION,gPt);
						kController.handleMessage(Request.ANIMATE_TO_MAP_WAYPOINT,gPt);
						kController.handleMessage(Request.UPDATE_HUD_GPSFIX, "3D fix "+gps.satellites_visible);
						kController.handleMessage(Request.UPDATE_MAP);

			

						break;
					}
					Boolean  record = (Boolean)kController.getMessage(Request.GET_STATUS_LOG);
					if(record){
						write_stream(ctx,gps.lat+" "+gps.lon+" "+gps.satellites_visible+" gps");
					}

				}else if(msg instanceof msg_command_ack){
					final msg_command_ack ack = (msg_command_ack)msg;			

					kController.handleMessage(Request.TOAST_MSG,JMAVLink.get_MAV_CMD(ack.command)+" --> "+JMAVLink.get_MAV_RESULT(ack.result));


				}else if(msg instanceof msg_nav_controller_output)
				{
					final msg_nav_controller_output ia = (msg_nav_controller_output)msg;		
					
					System.out.println("target_bearing =>"+ia.target_bearing);
					System.out.println("nav_bearing =>"+ia.nav_bearing);
					System.out.println("xtrack_error  =>"+ia.xtrack_error);
					System.out.println("Wind Direction  =>"+ia.nav_roll);
					kController.handleMessage(Request.UPDATE_IA_INFO,ia);
			
		
				}else if(msg instanceof msg_servo_output_raw){
					final msg_servo_output_raw rawservo = (msg_servo_output_raw)msg;	
					
					//System.out.println("raw servo 1 =>"+rawservo.servo1_raw);
				//	System.out.println("raw servo 2 =>"+rawservo.servo2_raw);
					
				}
				else {

					//	System.out.println(msg);
				}




			}

			@Override
			public void connected(final MavLinkEvent evt) 
			{
				kController.handleMessage(Request.MAVLINK_ISCONNECTED,evt);

				kController.handleMessage(Request.TOAST_MSG,((MavlinkEventConnected)evt).msg);
			}

			@Override
			public void disconnected(final MavLinkEvent evt) 
			{
				kController.handleMessage(Request.MAVLINK_ISDISCONNECTED,evt);
				kController.handleMessage(Request.TOAST_MSG,((MavlinkEventDisconnected)evt).msg);
			}
		});

	}

	public JMAVLink getMavlink() {
		return mavlink;
	}


}
