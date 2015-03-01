/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/**
 * Licensed under the GNU LESSER GENERAL PUBLIC LICENSE, Version 3, 29 June 2007;
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.gnu.org/licenses/lgpl-3.0.txt
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package eu.powet.groundcopter.views;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.List;


import org.osmdroid.DefaultResourceProxyImpl;
import org.osmdroid.ResourceProxy;
import org.osmdroid.api.IGeoPoint;
import org.osmdroid.tileprovider.IRegisterReceiver;
import org.osmdroid.tileprovider.MapTileProviderBasic;
import org.osmdroid.tileprovider.modules.INetworkAvailablityCheck;
import org.osmdroid.tileprovider.modules.NetworkAvailabliltyCheck;
import org.osmdroid.tileprovider.tilesource.TileSourceFactory;
import org.osmdroid.tileprovider.util.SimpleRegisterReceiver;
import org.osmdroid.util.GeoPoint;
import org.osmdroid.views.MapController;
import org.osmdroid.views.MapView;
import org.osmdroid.views.overlay.Overlay;

import com.mavlink.messages.common.msg_attitude;
import com.mavlink.messages.common.msg_nav_controller_output;
import com.mavlink.messages.common.msg_sys_status;


import android.app.Activity;
import android.app.AlertDialog;

import android.content.Context;
import android.content.DialogInterface;
import android.os.Vibrator;
import android.support.v4.view.GestureDetectorCompat;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.widget.*;
import eu.powet.groundcopter.GeoPointMission;
import eu.powet.groundcopter.MapPosition;
import eu.powet.groundcopter.TrackMap;
import eu.powet.groundcopter.WaypointsUI;

import eu.powet.groundcopter.controller.IController;
import eu.powet.groundcopter.controller.Request;

import eu.powet.groundcopter.utils.FTDriver;
import eu.powet.groundcopter.utils.EventUpdaterUI;
import eu.powet.groundcopter.utils.ViewChangeListener;
import eu.powet.groundcopter.views.widgets.HUD;



/**
 * Created by jed
 * User: jedartois@gmail.com
 * Date: 08/03/12
 * Time: 16:27
 */
public class BaseGroundCopterUI extends LinearLayout {

	private Activity ctx=null;
	private IController kController;
	//ui

	private HUD hud;
	private MapView mapView;
	private MapController mapController;

	private TrackMap track;
	private MapPosition copter_position;
	private MapPosition tablet_position;
	private WaypointsUI waypoints;

	private RelativeLayout layout_hud_map ;
	private LinearLayout layout_buttons;


	// buttons
	private Button bt_connect;
	private Button bt_deconnect;
	private Button bt_follow_me;
	private Button bt_request_stream;
	private Button bt_arm_disarm;
	private Button bt_display_hud;
	private Button bt_exit;
	private Button bt_set_home_location;
	private Button bt_goto_home_location;
	private Button bt_read_mission;
	private Button bt_write_mission;
	private Button bt_clean_mission;
	private Button bt_record;
	private Button bt_pilot;
	
	private TextView heading_error;
	private TextView bearing;
	private TextView distance;
	private TextView winddirection;

	private CheckBox baudrate_115200;
	private CheckBox baudrate_57600;


	// strings
	private final String txt_stream_start = "Start Stream";
	private final String txt_stream_stop = "Stop Stream";
	private final String txt_arm = "ARMED";
	private final String txt_disarm = "DISARMED";
	private final String txt_followme_start = "Start Follow ME";
	private final String txt_followme_stop = "Stop Follow ME";
	
	private final String txt_auto = "Démarrer la Mission";
	private final String txt_manuel = "Stopper la Mission";

	// states
	private boolean b_display_hud = false;
	private boolean b_request_stream = true;
	private boolean b_copter_is_armed=false;
	private boolean pilot_auto=false;
	private boolean b_copter_is_followingme=false;
	private boolean b_copter_record= false;

	public BaseGroundCopterUI(IController kController)
	{
		super(kController.getCurrentActivity());
		ctx = kController.getCurrentActivity();
		this.kController = kController;

		copter_position = new MapPosition(ctx,MapPosition.Type.Quadcopter);
		tablet_position = new MapPosition(ctx,MapPosition.Type.User);

		init_gui();
		init_buttons();
		init_map();
		init_hud();
		init_callbacks();

		addView(layout_buttons);
		layout_hud_map.addView(mapView);
		layout_hud_map.addView(hud);
		addView(layout_hud_map);

		// 
		kController.getViewsmanager().addEventListener(new ViewChangeListener() 
		{
			@Override
			public void update(EventUpdaterUI evt) {

				switch(evt.getReq()){

				
				case HEARTBEAT:
			
					break;
					
				case UPDATE_IA_INFO:
									
					msg_nav_controller_output infos = (msg_nav_controller_output)evt.getData();
					
					bearing.setText("Heading  "+infos.nav_bearing);
					bearing.setText("Target Heading  "+infos.target_bearing);
					heading_error.setText("Heading error  "+infos.xtrack_error);
					winddirection.setText("Wind "+infos.nav_roll);
					distance.setText("Distance "+infos.wp_dist);
		

					break;
					
				case ENABLE_BUTTONS:
					enable_buttons();
					break;

				case DISABLE_BUTTONS:
					disable_buttons();
					break;
				case DISABLE_HUD:
					display_hud(false);
					break;

				case ANIMATE_TO_MAP_WAYPOINT:
					mapController.animateTo((IGeoPoint) evt.getData());
					break;

				case ENABLE_HUD:
					display_hud(true);
					break;

				case  UPDATE_HUD_ALTITUDE:
					hud.setAltitude((Float) evt.getData());
					break;

				case UPDATE_HUD_GPSFIX:
					hud.setGPSFix(evt.getData().toString());
				
					break;

				case UPDATE_FLIGHTDATA:
					msg_attitude t = (msg_attitude)evt.getData();
					hud.newFlightData(t.roll,t.pitch,t.yaw);
			
					break;

				case ADD_TRACK:
					track.addPoint((GeoPoint) evt.getData());
					break;

				case SET_USER_POSITION:
					tablet_position.setPositiongps((GeoPointMission) evt.getData());
					break;
				case SET_DRONE_POSITION:
					copter_position.setPositiongps((GeoPointMission) evt.getData());
					break;
				case SYS_STATUS:
					msg_sys_status t1 = (msg_sys_status)evt.getData();
					hud.setbatteryMVolt(t1.voltage_battery);
					hud.setBatteryRemaining(t1.battery_remaining);
					break;
				case CLEAN_TRACK:
					track.clean();
					break;

				case UPDATE_MAP:

				
					mapView.invalidate();
					break;

				case IS_ARMED:
					hud.setNavMode(txt_arm);
					b_copter_is_armed = false;
					bt_arm_disarm.setText("SET "+txt_disarm);
					break;

				case IS_DISARMED:
					hud.setNavMode(txt_disarm);
					b_copter_is_armed = true;
					bt_arm_disarm.setText("SET "+txt_arm);
					break;
				}
			}

		});
	}



	public void init_gui(){
		setOrientation(LinearLayout.VERTICAL);

	}
	public void init_buttons(){

		// Buttons 
		bt_connect = new Button(ctx);
		bt_connect.setText("Connect");
		bt_deconnect = new Button(ctx);
		bt_deconnect.setText("Disconnect");
		bt_deconnect.setEnabled(false);
		bt_follow_me = new Button(ctx);
		bt_follow_me.setText(txt_followme_start);
		bt_follow_me.setEnabled(false);
		bt_request_stream = new Button(ctx);
		bt_request_stream.setText(txt_stream_start);
		bt_request_stream.setEnabled(false);
		bt_display_hud = new Button(ctx);
		bt_display_hud.setText("Disable HUD");
		bt_arm_disarm = new Button(ctx);
		bt_arm_disarm.setText(txt_disarm);
		bt_exit = new Button(ctx);
		bt_exit.setText("Quitter");
		bt_set_home_location = new Button(ctx);
		bt_set_home_location.setText("Set Home");
		bt_goto_home_location = new Button(ctx);
		bt_goto_home_location.setText("Go to Home");
		bt_read_mission =new Button(ctx);
		bt_read_mission.setText("Télécharger la Mission");
		bt_write_mission =new Button(ctx);
		bt_write_mission.setText("Envoyer la Mission");
		bt_clean_mission = new Button(ctx);
		bt_clean_mission.setText("Effacer la Mission");
		bt_record = new Button(ctx);
		bt_record.setText("Start Record");
		
		heading_error = new TextView(ctx);
		
		heading_error.setText("0");
		bearing = new TextView(ctx);
		bearing.setText("0");
		distance = new TextView(ctx);
		distance.setText("0");
		winddirection= new TextView(ctx);
		winddirection.setText("0");
		
		bt_pilot = new Button(ctx);
		bt_pilot.setText(txt_auto);

		baudrate_115200 = new CheckBox(ctx);
		baudrate_115200.setText("115200");
		baudrate_115200.setChecked(true);
		baudrate_57600 = new CheckBox(ctx);
		baudrate_57600.setText("57600");
	


		layout_buttons = new LinearLayout(ctx);
		layout_buttons.setOrientation(LinearLayout.HORIZONTAL);

		layout_buttons.addView(bt_connect);
		layout_buttons.addView(bt_deconnect);
		layout_buttons.addView(baudrate_57600);
		layout_buttons.addView(baudrate_115200);
		layout_buttons.addView(bt_pilot);
		
		layout_buttons.addView(bt_display_hud);
		//layout_buttons.addView(bt_request_stream);
	//	layout_buttons.addView(bt_arm_disarm);
		layout_buttons.addView(bt_read_mission);
		layout_buttons.addView(bt_write_mission);
		layout_buttons.addView(bt_clean_mission);
	//	layout_buttons.addView(bt_follow_me);
	//	layout_buttons.addView(bt_set_home_location);
	//	layout_buttons.addView(bt_goto_home_location);
		//layout_buttons.addView(bt_record);
		

		addView(heading_error);
		addView(bearing);
		addView(distance);
		addView(winddirection);
		
		layout_buttons.addView(bt_exit);



	}

	public void init_hud(){

		layout_hud_map = new RelativeLayout(ctx);
		hud = new HUD(ctx);
		hud.setMinimumHeight(100);
		hud.setMinimumWidth(100);


	}
	public void init_map(){
		IRegisterReceiver receiver = new SimpleRegisterReceiver(ctx);
		INetworkAvailablityCheck networkAvailablityCheck = new NetworkAvailabliltyCheck(ctx);
		ResourceProxy resProxy = new DefaultResourceProxyImpl(ctx);
		MapTileProviderBasic tileProvider = new MapTileProviderBasic(  receiver, networkAvailablityCheck, TileSourceFactory.MAPQUESTOSM);
		mapView = new MapView(ctx, 256, resProxy, tileProvider);
		mapController =  mapView.getController();
		mapController.setZoom(16);


		//	mapView.setBuiltInZoomControls(true);
		mapView.setMultiTouchControls(true);
		mapView.setMinimumHeight(ctx.getWindowManager().getDefaultDisplay().getHeight() );
		mapView.setMinimumWidth(ctx.getWindowManager().getDefaultDisplay().getWidth() );

		List<Overlay> listOfOverlays = mapView.getOverlays();
		track = new TrackMap(ctx, mapView);
		waypoints = new WaypointsUI(ctx,kController);
		listOfOverlays.add(copter_position);
		listOfOverlays.add(tablet_position);
		listOfOverlays.add(waypoints);
		GeoPoint gPt = new GeoPoint(48.120282,-1.650592); // default location at IRISA
		mapController.setCenter(gPt);

	}


	public void init_callbacks(){

		final GestureDetectorCompat mGestureDetector2 = new GestureDetectorCompat(ctx,new GestureDetector.OnGestureListener() {
			
			@Override
			public boolean onSingleTapUp(MotionEvent e) {
				// TODO Auto-generated method stub
				return false;
			}
			
			@Override
			public void onShowPress(MotionEvent e) {
				// TODO Auto-generated method stub
				
			}
			
			@Override
			public boolean onScroll(MotionEvent e1, MotionEvent e2, float distanceX,
					float distanceY) {
				// TODO Auto-generated method stub
				return false;
			}
			
			@Override
			public void onLongPress(final MotionEvent e) {
				ctx.runOnUiThread(new Runnable() {

					@Override
					public void run() {
					System.out.println(e.toString());
					
				
						GeoPoint m = (GeoPoint) mapView.getProjection().fromPixels(e.getX(),e.getY());
			

						GeoPointMission wp = new GeoPointMission(m,0);
						kController.handleMessage(Request.ADD_WAYPOINT, wp);
					
						Vibrator v = (Vibrator) ctx.getSystemService(Context.VIBRATOR_SERVICE);
						 // Vibrate for 500 milliseconds
						 v.vibrate(100);
						
			
					}
				});
				
			}
			
			@Override
			public boolean onFling(MotionEvent e1, MotionEvent e2, float velocityX,
					float velocityY) {
				// TODO Auto-generated method stub
				return false;
			}
			
			@Override
			public boolean onDown(MotionEvent e) {
				// TODO Auto-generated method stub
				return false;
			}
		} );
		


		mapView.setOnTouchListener(new View.OnTouchListener() {

			@Override
			public boolean onTouch(View v, MotionEvent e) {
				return mGestureDetector2.onTouchEvent(e);
			}


		});
		bt_read_mission.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) 
			{
				kController.handleMessage(Request.CLEAR_UI_WAYPOINTS);
				kController.handleMessage(Request.READ_WAYPOINTS);
			}

		});
		bt_write_mission.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) 
			{
				kController.handleMessage(Request.WRITE_WAYPOINTS);
			}

		});

		bt_clean_mission.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) 
			{
				kController.handleMessage(Request.DELETE_WAYPOINTS);
			}

		});



		bt_record.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) {
				if(b_copter_record){
					b_copter_record = false;
					kController.handleMessage(Request.DISABLE_LOG);
					bt_record.setText("Start Record");
				}else {
					b_copter_record = true;
					kController.handleMessage(Request.ENABLE_LOG);
					bt_record.setText("Stop Record");
				}
			}
		});

		bt_set_home_location.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) 
			{

				/*MAV_CMD_DO_SET_HOME	Changes the home location either to the current location or a specified location.
					Mission Param #1	Use current (1=use current location, 0=use specified location)
					Mission Param #2	Empty
					Mission Param #3	Empty
					Mission Param #4	Empty
					Mission Param #5	Latitude
					Mission Param #6	Longitude
					Mission Param #7	Altitude


				double lat =   48.727209;
				double lon =  -2.00267;
				int  alt = 15;
				GeoPointMission here = new GeoPointMission(new GeoPoint(lat, lon,alt));


					MavlinkHelper.flyhere(mavlink, here);

				 */





			}

		});

		bt_goto_home_location.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) 
			{
				DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface dialog, int which) {
						switch (which){
						case DialogInterface.BUTTON_POSITIVE:

							kController.handleMessage(Request.RETURN_TO_LAUNCH);

							break;
						}}};




						AlertDialog.Builder builder = new AlertDialog.Builder(ctx);

						builder.setMessage("Are you sure to go to home?").setPositiveButton("Yes", dialogClickListener)
						.setNegativeButton("No", dialogClickListener).show();



			}

		});



		bt_request_stream.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{
				if(b_request_stream){
					kController.handleMessage(Request.START_STREAM);
					b_request_stream = false;
					bt_request_stream.setText(txt_stream_stop);
				}else {
					b_request_stream = true;
					kController.handleMessage(Request.STOP_STREAM);
					bt_request_stream.setText(txt_stream_start);
				}
			}

		});
		bt_display_hud.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{
				if(b_display_hud){
					kController.handleMessage(Request.ENABLE_HUD);
					b_display_hud = false;
				}else {
					b_display_hud = true;
					kController.handleMessage(Request.DISABLE_HUD);
				}

			}

		});



		bt_connect.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) {
				bt_connect.setEnabled(false);
				bt_deconnect.setEnabled(true);

				baudrate_57600.setEnabled(false);
				baudrate_115200.setEnabled(false);


				kController.handleMessage(Request.CONNECT);
			}

		});




		bt_deconnect.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) {

				bt_connect.setEnabled(true);
				bt_deconnect.setEnabled(false);
				baudrate_57600.setEnabled(true);
				baudrate_115200.setEnabled(true);
				kController.handleMessage(Request.STOP_STREAM);
				kController.handleMessage(Request.DISABLE_BUTTONS);
				kController.handleMessage(Request.DISCONNECT);
			}

		});



		bt_pilot.setOnClickListener(new OnClickListener() {

			@Override

			public void onClick(View v) {

				if(pilot_auto == false){
					
					kController.handleMessage(Request.PILOT_AUTO);
					pilot_auto = true;
					bt_pilot.setText(txt_manuel);
				}else {
					kController.handleMessage(Request.PILOT_MANUEL);
					pilot_auto = false;
					bt_pilot.setText(txt_auto);
					
				}
				/*
				DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface dialog, int which) {
						switch (which){
						case DialogInterface.BUTTON_POSITIVE:

							
						
							break;

						case DialogInterface.BUTTON_NEGATIVE:
							//No button clicked
							break;
						}
					}
				};

				AlertDialog.Builder builder = new AlertDialog.Builder(ctx);

				builder.setMessage("Confirmez vous le changement de mode ?").setPositiveButton("Yes", dialogClickListener)
				.setNegativeButton("No", dialogClickListener).show();
				*/
			
	
			}

		});



		bt_exit.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{
				kController.handleMessage(Request.DISCONNECT);
				kController.handleMessage(Request.EXIT);
			}

		});
		baudrate_115200.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{
				baudrate_57600.setChecked(false);
				baudrate_115200.setChecked(true);

				kController.handleMessage(Request.CHANGE_BAUDRATE,FTDriver.BAUD115200);

			}

		});

		baudrate_57600.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{
				baudrate_115200.setChecked(false);
				baudrate_57600.setChecked(true);

				kController.handleMessage(Request.CHANGE_BAUDRATE,FTDriver.BAUD57600);
			}

		});

		bt_arm_disarm.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{



				/*
				 * 		    In a MAVLINK_MSG_ID_COMMAND_LONG
			    A MAV_CMD of type MAV_CMD_COMPONENT_ARM_DISARM
			    with component id MAV_COMP_ID_SYSTEM_CONTROL = 250,
			    uses param index 1 to specify an arm/disarm motors event: 1 to arm,
			    0 to disarm
				  			//MAVLINK_MSG_ID_COMMAND_LONG*/		
				DialogInterface.OnClickListener dialogClickListener = new DialogInterface.OnClickListener() {
					@Override
					public void onClick(DialogInterface dialog, int which) {
						switch (which){
						case DialogInterface.BUTTON_POSITIVE:

							if(!b_copter_is_armed)
							{
								kController.handleMessage(Request.SET_ARMED);
							}else 
							{
								kController.handleMessage(Request.SET_DISARMED);
							}
							break;

						case DialogInterface.BUTTON_NEGATIVE:
							//No button clicked
							break;
						}
					}
				};

				AlertDialog.Builder builder = new AlertDialog.Builder(ctx);

				builder.setMessage("Are you sure to ARM/DISARM ?").setPositiveButton("Yes", dialogClickListener)
				.setNegativeButton("No", dialogClickListener).show();


			}

		});


		bt_follow_me.setOnClickListener(new OnClickListener() {
			@Override
			public void onClick(View v) 
			{


				if(!b_copter_is_followingme)
				{

					AlertDialog.Builder alert = new AlertDialog.Builder(ctx);  

					alert.setTitle("Follow Me ");
					alert.setMessage("Set Altitude");  

					final EditText input_altitude = new EditText(ctx);

					input_altitude.setText("10");


					alert.setView(input_altitude); 
					alert.setPositiveButton("ok", new DialogInterface.OnClickListener() {  
						public void onClick(DialogInterface dialog, int whichButton) 
						{  
							try
							{
								int 	altitude  = Integer.parseInt(input_altitude.getText().toString());
								kController.handleMessage(Request.DELETE_WAYPOINTS);
								kController.handleMessage(Request.SET_FOLLOWME_ALTITUDE,altitude);
								kController.handleMessage(Request.START_FOLLOWME);
								bt_follow_me.setText(txt_followme_stop);
								b_copter_is_followingme = true;		
							}catch(Exception e)
							{
								kController.handleMessage(Request.TOAST_MSG,"Error ",e.getMessage());
							}


						}  
					});
					alert.setNegativeButton("cancel",  new DialogInterface.OnClickListener() {

						@Override
						public void onClick(DialogInterface dialog,
								int which) {
							// TODO Auto-generated method stub

						}

					});
					alert.show();

				}else 
				{
					kController.handleMessage(Request.STOP_FOLLOWME);
					bt_follow_me.setText(txt_followme_start);
					b_copter_is_followingme = false;
				}


			}

		});
	}


	public void display_hud(boolean enable){
		if(enable){
			hud.setVisibility(0);
			bt_display_hud.setText("Disable HUD");		

		}else {
			hud.setVisibility(4);
			bt_display_hud.setText("Enable HUD");	
		}


	}

	public void enable_buttons(){
		bt_follow_me.setEnabled(true);
		bt_request_stream.setEnabled(true);
		bt_arm_disarm.setEnabled(true);
		bt_set_home_location.setEnabled(true);
		bt_read_mission.setEnabled(true);
		bt_write_mission.setEnabled(true);
		bt_clean_mission.setEnabled(true);
		bt_goto_home_location.setEnabled(true);
		bt_pilot.setEnabled(true);

	}
	public void disable_buttons(){
		bt_deconnect.setEnabled(false);
		bt_follow_me.setEnabled(false);
		bt_request_stream.setEnabled(false);
		bt_arm_disarm.setEnabled(false);
		bt_set_home_location.setEnabled(false);
		bt_read_mission.setEnabled(false);
		bt_write_mission.setEnabled(false);
		bt_clean_mission.setEnabled(false);
		bt_goto_home_location.setEnabled(false);
		bt_pilot.setEnabled(false);
		baudrate_57600.setEnabled(true);
		baudrate_115200.setEnabled(true);
		bt_connect.setEnabled(true);
	}


}
