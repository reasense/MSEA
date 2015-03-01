package eu.powet.groundcopter.utils;

import com.mavlink.messages.common.msg_command_long;
import com.mavlink.messages.common.msg_mission_clear_all;
import com.mavlink.messages.common.msg_mission_count;
import com.mavlink.messages.common.msg_mission_item;
import com.mavlink.messages.common.msg_mission_request_list;
import com.mavlink.messages.common.msg_request_data_stream;



import eu.powet.groundcopter.GeoPointMission;
import eu.powet.groundcopter.events.JMAVLink;

public class MavlinkHelper {

	public static boolean nav_return_to_launch(JMAVLink mavlink){
		msg_command_long cmd = new msg_command_long();
		cmd.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		cmd.command = JMAVLink.MAV_CMD.MAV_CMD_NAV_RETURN_TO_LAUNCH;
		return mavlink.writeMessage(cmd);
	}
	
	public static boolean set_armed(JMAVLink mavlink,boolean enable)
	{
		msg_command_long cmd = new msg_command_long();
		cmd.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		cmd.command = JMAVLink.MAV_CMD.MAV_CMD_COMPONENT_ARM_DISARM;
		cmd.target_component = JMAVLink.MAV_COMPONENT.MAV_COMP_ID_SYSTEM_CONTROL;
		if(!enable){
			cmd.param1 = 1;	
		}else {
			cmd.param1 = 0;	
		}
		return	mavlink.writeMessage(cmd);
	}
	
	public static boolean clear_waypoints(JMAVLink mavlink)
	{
	 	msg_mission_clear_all clear_mission = new msg_mission_clear_all();
		clear_mission.target_component = 1;
		clear_mission.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		return mavlink.writeMessage(clear_mission);
	}
	
	public static boolean flyhere(JMAVLink mavlink,GeoPointMission p)
	{
		if(p != null)
		{
			msg_mission_item req = new msg_mission_item();
			req.seq =0;
			req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
			req.target_component = 0;
			req.frame = JMAVLink. MAV_FRAME.MAV_FRAME_MISSION;
			req.x =   (float) (p.getLatitudeE6() /1e6);
			req.y =   (float) (p.getLongitudeE6()/1e6);

			req.z = (float)p.getAltitude();
			req.command = JMAVLink.MAV_CMD.MAV_CMD_NAV_WAYPOINT;
			req.autocontinue = 0;
			req.param1 = 0;
			req.param2 = 0; //milliseconds
			req.param3 = 0;
			req.param4 = 0;
			//current = 2 is a flag to tell us this is a "guided mode" waypoint and not for the mission
			req.current = 2; 
			System.out.println(" FLY TO HERE "+req.seq+"msg_mission_item  x= "+req.x+" y="+req.y+" "+req.z+" autocontinue="+req.autocontinue+" command="+req.command+" "+req.param1);
			return mavlink.writeMessage(req);
		}
		return false;
	}

	public static boolean request_list_waypoints(JMAVLink mavlink){
		msg_mission_request_list list = new msg_mission_request_list();
		list.target_component = 0;
		list.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		return mavlink.writeMessage(list);
	}

	public static boolean initialize_procedure_addwaypoints(JMAVLink mavlink,int number_of_waypoints){
		msg_mission_count list = new msg_mission_count();
		list.target_component = 0;
		list.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		list.count = number_of_waypoints;
		return mavlink.writeMessage(list);
	}


	public static boolean set_auto(JMAVLink mavlink,boolean enable)
	{
		msg_command_long cmd = new msg_command_long();
		cmd.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		cmd.command = JMAVLink.MAV_CMD.MAV_CMD_DO_SET_MODE;
		cmd.target_component = JMAVLink.MAV_COMPONENT.MAV_COMP_ID_SYSTEM_CONTROL;
		if(enable){
			cmd.param1 = JMAVLink.MAV_MODE.MAV_MODE_AUTO_ARMED;	
		}else {
			cmd.param1 =JMAVLink.MAV_MODE.MAV_MODE_MANUAL_ARMED;	
		}
		return	mavlink.writeMessage(cmd);
	}

	public static void helper_stream(JMAVLink mavlink,boolean enable){
		/*INFO ArdupilotMega.MAVLink - Request stream EXTENDED_STATUS at 2 hz
INFO ArdupilotMega.MAVLink - Request stream POSITION at 3 hz
INFO ArdupilotMega.MAVLink - Request stream EXTRA1 at 10 hz
INFO ArdupilotMega.MAVLink - Request stream EXTRA2 at 10 hz
INFO ArdupilotMega.MAVLink - Request stream EXTRA3 at 2 hz
INFO ArdupilotMega.MAVLink - Request stream RAW_SENSORS at 2 hz
INFO ArdupilotMega.MAVLink - Request stream RC_CHANNELS at 2 hz
		 */
		msg_request_data_stream req;

		req = new msg_request_data_stream();
		req.req_message_rate = 2;//		 Request stream EXTENDED_STATUS at 2 hz
		req.req_stream_id = JMAVLink.MAV_DATA_STREAM.MAV_DATA_STREAM_EXTENDED_STATUS; 

		if(enable)
		{
			req.start_stop = 1;	
		}else {
			req.start_stop = 0;
		}

		req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		req.target_component = 0;
		mavlink.writeMessage(req);


		req = new msg_request_data_stream();
		req.req_message_rate = 5;// Request stream EXTRA1 at 5 hz
		req.req_stream_id = JMAVLink.MAV_DATA_STREAM.MAV_DATA_STREAM_POSITION; 
		if(enable){
			req.start_stop = 1;	
		}else {
			req.start_stop = 0;
		}

		mavlink.writeMessage(req);

		req = new msg_request_data_stream();
		req.req_message_rate = 5;// Request stream EXTRA1 at 5 hz
		req.req_stream_id = JMAVLink.MAV_DATA_STREAM.MAV_DATA_STREAM_EXTRA1; 
		if(enable)
		{
			req.start_stop = 1;	
		}else 
		{
			req.start_stop = 0;
		}

		req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		req.target_component = 0;
		//mavlink.writeMessage(req);


		req = new msg_request_data_stream();
		req.req_message_rate = 3;
		req.req_stream_id = JMAVLink.MAV_DATA_STREAM.MAV_DATA_STREAM_EXTRA2; 

		if(enable){
			req.start_stop = 1;	
		}else {
			req.start_stop = 0;
		}
		req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		req.target_component = 0;
		mavlink.writeMessage(req);

		req = new msg_request_data_stream();
		req.req_message_rate = 3;
		req.req_stream_id = JMAVLink.MAV_DATA_STREAM.MAV_DATA_STREAM_EXTRA3; 

		if(enable){
			req.start_stop = 1;	
		}else {
			req.start_stop = 0;
		}
		req.target_system = JMAVLink.MAVLINK_ARDU_MEGA_SYSID;
		req.target_component = 0;
		mavlink.writeMessage(req);

	}


}
