package eu.powet.groundcopter.events;

import java.lang.reflect.Field;


import com.mavlink.messages.IMAVLinkMessage;

import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.hardware.usb.UsbManager;
import eu.powet.groundcopter.MavlinkNative;
import eu.powet.groundcopter.utils.FTDriver;


public class JMAVLink implements IJMAVLink,Runnable{

	private MavlinkNative nmavlink = null;
	private FTDriver mSerial;
	private static final String ACTION_USB_PERMISSION = " eu.powet.groundcopter.USB_PERMISSION";	
	private Thread serial;
	private int baudrate;
	private boolean started  = false;
	private EventListenerListMavLink listenerList = new EventListenerListMavLink();
	private Context ctx;

	public static int MAVLINK_ARDU_MEGA_SYSID = 1;
	public static int MAVLINK_ARDU_COPTER_MEGA_SYSID = 7;

	public JMAVLink(Context c){
		nmavlink = new MavlinkNative(this);
		this.ctx = c;
	}

	public synchronized boolean writeMessage(IMAVLinkMessage msg)
	{
		if(nmavlink == null || mSerial ==null){
			return false;
		}
		byte[] data = nmavlink.createMessage(msg);
		if(data != null && mSerial.write(data) == data.length)
		{
			return true;
		}else 
		{
			return false;
		}
	}

	public boolean connect(int baudrate){
		this.baudrate = baudrate;
		started = true;
		mSerial = new FTDriver((UsbManager)ctx.getSystemService(Context.USB_SERVICE));
		PendingIntent permissionIntent = PendingIntent.getBroadcast(ctx, 0, new Intent(ACTION_USB_PERMISSION), 0);
		mSerial.setPermissionIntent(permissionIntent); 
		serial = new Thread(this);
		serial.start();
		return true;
	}

	public void disconnect(){
		if(serial != null){
			started = false;
			mSerial.end();
			try {
				serial.join(1500);
			} catch (InterruptedException e) {
				// ignore
			}
		}
	}
	public MavlinkNative getJni_mavlink() {
		return nmavlink;
	}


	public void addEventListener (MavLinkEventListener listener) {
		if(listenerList != null)
		{
			listenerList.add(MavLinkEventListener.class, listener);
		}
	}

	public void removeEventListener (MavLinkEventListener listener) {
		if(listenerList != null)
		{
			listenerList.remove(MavLinkEventListener.class, listener);
		}
	}

	public void fireEvent (MavLinkEvent evt)
	{
		if(listenerList !=null )
		{
			Object[] listeners = listenerList.getListenerList();
			if(listeners != null)
			{
				for (int i = 0; i < listeners.length; i += 2) 
				{
					if(listeners[i] == MavLinkEventListener.class){

						if (evt instanceof MavlinkEventConnected)
						{
							((MavLinkEventListener) listeners[i + 1]).connected(evt);
						}else if (evt instanceof MavlinkEventDisconnected)
						{
							((MavLinkEventListener) listeners[i + 1]).disconnected(evt);

						}else if (evt instanceof MavLinkEvent)	
						{
							((MavLinkEventListener) listeners[i + 1]).receive((MavLinkEvent)evt,evt.getIMAVLinkMessage());
						}
					}

				}
			}
		}
	}




	@Override
	public void run() 
	{
		int tentatives =0;
		boolean resu = false;
		do 
		{
			resu =mSerial.begin(baudrate);
			try 
			{
				Thread.sleep(500);
				tentatives++;
			} catch (InterruptedException e) {

			}
		}while(resu == false && tentatives < 5);

		if(!resu)
		{
			started = false; 
			MavlinkEventDisconnected deco = 	new MavlinkEventDisconnected(this, null);
			deco.msg = "Unable to connect using serial port with baudrate "+baudrate;
			fireEvent(deco);
		}else {
			MavlinkEventConnected connected = new MavlinkEventConnected(this,null);
			connected.msg = "Connected to serial port with baudrate "+baudrate;
			fireEvent(connected);	
		}

		int len;
		byte[] rbuf = new byte[2048];

		while(started == true)
		{
			if(mSerial.isConnected())
			{
				len = mSerial.read(rbuf);
				if(len > 0)
				{
					getJni_mavlink().forward(len,rbuf);
				}

			}else 
			{
				started = false;	
				fireEvent(new MavlinkEventDisconnected(this, null));
			}

		}

	}

	public class MAV_AUTOPILOT{
		public final static int MAV_AUTOPILOT_GENERIC=0; //, * Generic autopilot, full support for everything | *
		public final static int MAV_AUTOPILOT_PIXHAWK=1; //, * PIXHAWK autopilot, http:
		public final static int MAV_AUTOPILOT_SLUGS=2; //, * SLUGS autopilot, http:
		public final static int MAV_AUTOPILOT_ARDUPILOTMEGA=3; //, * ArduPilotMega 
		public final static int MAV_AUTOPILOT_OPENPILOT=4; //, * OpenPilot, http:
		public final static int MAV_AUTOPILOT_GENERIC_WAYPOINTS_ONLY=5; //, * Generic autopilot only supporting simple waypoints | *
		public final static int MAV_AUTOPILOT_GENERIC_WAYPOINTS_AND_SIMPLE_NAVIGATION_ONLY=6; //, * Generic autopilot supporting waypoints and other simple navigation commands | *
		public final static int MAV_AUTOPILOT_GENERIC_MISSION_FULL=7; //, * Generic autopilot supporting the full mission command set | *
		public final static int MAV_AUTOPILOT_INVALID=8; //, * No valid autopilot, e.g. a GCS or other MAVLink component | *
		public final static int MAV_AUTOPILOT_PPZ=9; //, * PPZ UAV - http:
		public final static int MAV_AUTOPILOT_UDB=10; //, * UAV Dev Board | *
		public final static int MAV_AUTOPILOT_FP=11; //, * FlexiPilot | *
		public final static int MAV_AUTOPILOT_ENUM_END=12; //, *  | *
	}

	public class MAV_MODE_FLAG{
		public final static int MAV_MODE_FLAG_CUSTOM_MODE_ENABLED=1; //, * 0b00000001 Reserved for future use. | *
		public final static int MAV_MODE_FLAG_TEST_ENABLED=2; //, * 0b00000010 system has a test mode enabled. This flag is intended for temporary system tests and should not be used for stable implementations. | *
		public final static int MAV_MODE_FLAG_AUTO_ENABLED=4; //, * 0b00000100 autonomous mode enabled, system finds its own goal positions. Guided flag can be set or not, depends on the actual implementation. | *
		public final static int MAV_MODE_FLAG_GUIDED_ENABLED=8; //, * 0b00001000 guided mode enabled, system flies MISSIONs 
		public final static int MAV_MODE_FLAG_STABILIZE_ENABLED=16; //, * 0b00010000 system stabilizes electronically its attitude (and optionally position). It needs however further control inputs to move around. | *
		public final static int MAV_MODE_FLAG_HIL_ENABLED=32; //, * 0b00100000 hardware in the loop simulation. All motors 
		public final static int MAV_MODE_FLAG_MANUAL_INPUT_ENABLED=64; //, * 0b01000000 remote control input is enabled. | *
		public final static int MAV_MODE_FLAG_SAFETY_ARMED=128; //, * 0b10000000 MAV safety set to armed. Motors are enabled 
		public final static int MAV_MODE_FLAG_ENUM_END=129; //, *  | *
	}

	public class MAV_MODE_FLAG_DECODE_POSITION{
		public final static int MAV_MODE_FLAG_DECODE_POSITION_CUSTOM_MODE=1; //, * Eighth bit: 00000001 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_TEST=2; //, * Seventh bit: 00000010 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_AUTO=4; //, * Sixt bit:   00000100 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_GUIDED=8; //, * Fifth bit:  00001000 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_STABILIZE=16; //, * Fourth bit: 00010000 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_HIL=32; //, * Third bit:  00100000 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_MANUAL=64; //, * Second bit: 01000000 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_SAFETY=128; //, * First bit:  10000000 | *
		public final static int MAV_MODE_FLAG_DECODE_POSITION_ENUM_END=129; //, *  | *
	}

	public class MAV_GOTO{
		public final static int MAV_GOTO_DO_HOLD=0; //, * Hold at the current position. | *
		public final static int MAV_GOTO_DO_CONTINUE=1; //, * Continue with the next item in mission execution. | *
		public final static int MAV_GOTO_HOLD_AT_CURRENT_POSITION=2; //, * Hold at the current position of the system | *
		public final static int MAV_GOTO_HOLD_AT_SPECIFIED_POSITION=3; //, * Hold at the position specified in the parameters of the DO_HOLD action | *
		public final static int MAV_GOTO_ENUM_END=4; //, *  | *
	}

	public class MAV_MODE{
		public final static int MAV_MODE_PREFLIGHT=0; //, * System is not ready to fly, booting, calibrating, etc. No flag is set. | *
		public final static int MAV_MODE_MANUAL_DISARMED=64; //, * System is allowed to be active, under manual (RC) control, no stabilization | *
		public final static int MAV_MODE_TEST_DISARMED=66; //, * UNDEFINED mode. This solely depends on the autopilot - use with caution, intended for developers only. | *
		public final static int MAV_MODE_STABILIZE_DISARMED=80; //, * System is allowed to be active, under assisted RC control. | *
		public final static int MAV_MODE_GUIDED_DISARMED=88; //, * System is allowed to be active, under autonomous control, manual setpoint | *
		public final static int MAV_MODE_AUTO_DISARMED=92; //, * System is allowed to be active, under autonomous control and navigation (the trajectory is decided onboard and not pre-programmed by MISSIONs) | *
		public final static int MAV_MODE_MANUAL_ARMED=192; //, * System is allowed to be active, under manual (RC) control, no stabilization | *
		public final static int MAV_MODE_TEST_ARMED=194; //, * UNDEFINED mode. This solely depends on the autopilot - use with caution, intended for developers only. | *
		public final static int MAV_MODE_STABILIZE_ARMED=208; //, * System is allowed to be active, under assisted RC control. | *
		public final static int MAV_MODE_GUIDED_ARMED=216; //, * System is allowed to be active, under autonomous control, manual setpoint | *
		public final static int MAV_MODE_AUTO_ARMED=220; //, * System is allowed to be active, under autonomous control and navigation (the trajectory is decided onboard and not pre-programmed by MISSIONs) | *
		public final static int MAV_MODE_ENUM_END=221; //, *  | *
	}

	public class MAV_STATE{
		public final static int MAV_STATE_UNINIT=0; //, * Uninitialized system, state is unknown. | *
		public final static int MAV_STATE_BOOT=1; //, * System is booting up. | *
		public final static int MAV_STATE_CALIBRATING=2; //, * System is calibrating and not flight-ready. | *
		public final static int MAV_STATE_STANDBY=3; //, * System is grounded and on standby. It can be launched any time. | *
		public final static int MAV_STATE_ACTIVE=4; //, * System is active and might be already airborne. Motors are engaged. | *
		public final static int MAV_STATE_CRITICAL=5; //, * System is in a non-normal flight mode. It can however still navigate. | *
		public final static int MAV_STATE_EMERGENCY=6; //, * System is in a non-normal flight mode. It lost control over parts or over the whole airframe. It is in mayday and going down. | *
		public final static int MAV_STATE_POWEROFF=7; //, * System just initialized its power-down sequence, will shut down now. | *
		public final static int MAV_STATE_ENUM_END=8; //, *  | *
	}

	public class MAV_TYPE{
		public final static int MAV_TYPE_GENERIC=0; //, * Generic micro air vehicle. | *
		public final static int MAV_TYPE_FIXED_WING=1; //, * Fixed wing aircraft. | *
		public final static int MAV_TYPE_QUADROTOR=2; //, * Quadrotor | *
		public final static int MAV_TYPE_COAXIAL=3; //, * Coaxial helicopter | *
		public final static int MAV_TYPE_HELICOPTER=4; //, * Normal helicopter with tail rotor. | *
		public final static int MAV_TYPE_ANTENNA_TRACKER=5; //, * Ground installation | *
		public final static int MAV_TYPE_GCS=6; //, * Operator control unit 
		public final static int MAV_TYPE_AIRSHIP=7; //, * Airship, controlled | *
		public final static int MAV_TYPE_FREE_BALLOON=8; //, * Free balloon, uncontrolled | *
		public final static int MAV_TYPE_ROCKET=9; //, * Rocket | *
		public final static int MAV_TYPE_GROUND_ROVER=10; //, * Ground rover | *
		public final static int MAV_TYPE_SURFACE_BOAT=11; //, * Surface vessel, boat, ship | *
		public final static int MAV_TYPE_SUBMARINE=12; //, * Submarine | *
		public final static int MAV_TYPE_HEXAROTOR=13; //, * Hexarotor | *
		public final static int MAV_TYPE_OCTOROTOR=14; //, * Octorotor | *
		public final static int MAV_TYPE_TRICOPTER=15; //, * Octorotor | *
		public final static int MAV_TYPE_FLAPPING_WING=16; //, * Flapping wing | *
		public final static int MAV_TYPE_ENUM_END=17; //, *  | *
	}

	public class MAV_COMPONENT{
		public final static int MAV_COMP_ID_ALL=0; //, *  | *
		public final static int MAV_COMP_ID_CAMERA=100; //, *  | *
		public final static int MAV_COMP_ID_SERVO1=140; //, *  | *
		public final static int MAV_COMP_ID_SERVO2=141; //, *  | *
		public final static int MAV_COMP_ID_SERVO3=142; //, *  | *
		public final static int MAV_COMP_ID_SERVO4=143; //, *  | *
		public final static int MAV_COMP_ID_SERVO5=144; //, *  | *
		public final static int MAV_COMP_ID_SERVO6=145; //, *  | *
		public final static int MAV_COMP_ID_SERVO7=146; //, *  | *
		public final static int MAV_COMP_ID_SERVO8=147; //, *  | *
		public final static int MAV_COMP_ID_SERVO9=148; //, *  | *
		public final static int MAV_COMP_ID_SERVO10=149; //, *  | *
		public final static int MAV_COMP_ID_SERVO11=150; //, *  | *
		public final static int MAV_COMP_ID_SERVO12=151; //, *  | *
		public final static int MAV_COMP_ID_SERVO13=152; //, *  | *
		public final static int MAV_COMP_ID_SERVO14=153; //, *  | *
		public final static int MAV_COMP_ID_MAPPER=180; //, *  | *
		public final static int MAV_COMP_ID_MISSIONPLANNER=190; //, *  | *
		public final static int MAV_COMP_ID_PATHPLANNER=195; //, *  | *
		public final static int MAV_COMP_ID_IMU=200; //, *  | *
		public final static int MAV_COMP_ID_IMU_2=201; //, *  | *
		public final static int MAV_COMP_ID_IMU_3=202; //, *  | *
		public final static int MAV_COMP_ID_GPS=220; //, *  | *
		public final static int MAV_COMP_ID_UDP_BRIDGE=240; //, *  | *
		public final static int MAV_COMP_ID_UART_BRIDGE=241; //, *  | *
		public final static int MAV_COMP_ID_SYSTEM_CONTROL=250; //, *  | *
		public final static int MAV_COMPONENT_ENUM_END=251; //, *  | *
	}

	public class MAV_FRAME{
		public final static int MAV_FRAME_GLOBAL=0; //, * Global coordinate frame, WGS84 coordinate system. First value 
		public final static int MAV_FRAME_LOCAL_NED=1; //, * Local coordinate frame, Z-up (x: north, y: east, z: down). | *
		public final static int MAV_FRAME_MISSION=2; //, * NOT a coordinate frame, indicates a mission command. | *
		public final static int MAV_FRAME_GLOBAL_RELATIVE_ALT=3; //, * Global coordinate frame, WGS84 coordinate system, relative altitude over ground with respect to the home position. First value 
		public final static int MAV_FRAME_LOCAL_ENU=4; //, * Local coordinate frame, Z-down (x: east, y: north, z: up) | *
		public final static int MAV_FRAME_ENUM_END=5; //, *  | *
	}

	public class MAVLINK_DATA_STREAM_TYPE{
		public final static int MAVLINK_DATA_STREAM_IMG_JPEG=1; //, *  | *
		public final static int MAVLINK_DATA_STREAM_IMG_BMP=2; //, *  | *
		public final static int MAVLINK_DATA_STREAM_IMG_RAW8U=3; //, *  | *
		public final static int MAVLINK_DATA_STREAM_IMG_RAW32U=4; //, *  | *
		public final static int MAVLINK_DATA_STREAM_IMG_PGM=5; //, *  | *
		public final static int MAVLINK_DATA_STREAM_IMG_PNG=6; //, *  | *
		public final static int MAVLINK_DATA_STREAM_TYPE_ENUM_END=7; //, *  | *
	}

	public class MAV_DATA_STREAM{
		public final static int MAV_DATA_STREAM_ALL=0; //, * Enable all data streams | *
		public final static int MAV_DATA_STREAM_RAW_SENSORS=1; //, * Enable IMU_RAW, GPS_RAW, GPS_STATUS packets. | *
		public final static int MAV_DATA_STREAM_EXTENDED_STATUS=2; //, * Enable GPS_STATUS, CONTROL_STATUS, AUX_STATUS | *
		public final static int MAV_DATA_STREAM_RC_CHANNELS=3; //, * Enable RC_CHANNELS_SCALED, RC_CHANNELS_RAW, SERVO_OUTPUT_RAW | *
		public final static int MAV_DATA_STREAM_RAW_CONTROLLER=4; //, * Enable ATTITUDE_CONTROLLER_OUTPUT, POSITION_CONTROLLER_OUTPUT, NAV_CONTROLLER_OUTPUT. | *
		public final static int MAV_DATA_STREAM_POSITION=6; //, * Enable LOCAL_POSITION, GLOBAL_POSITION
		public final static int MAV_DATA_STREAM_EXTRA1=10; //, * Dependent on the autopilot | *
		public final static int MAV_DATA_STREAM_EXTRA2=11; //, * Dependent on the autopilot | *
		public final static int MAV_DATA_STREAM_EXTRA3=12; //, * Dependent on the autopilot | *
		public final static int MAV_DATA_STREAM_ENUM_END=13; //, *  | *
	}

	public class MAV_ROI{
		public final static int MAV_ROI_NONE=0; //, * No region of interest. | *
		public final static int MAV_ROI_WPNEXT=1; //, * Point toward next MISSION. | *
		public final static int MAV_ROI_WPINDEX=2; //, * Point toward given MISSION. | *
		public final static int MAV_ROI_LOCATION=3; //, * Point toward fixed location. | *
		public final static int MAV_ROI_TARGET=4; //, * Point toward of given id. | *
		public final static int MAV_ROI_ENUM_END=5; //, *  | *
	}

	public class MAV_CMD_ACK{
		public final static int MAV_CMD_ACK_OK=1; //, * Command 
		public final static int MAV_CMD_ACK_ERR_FAIL=2; //, * Generic error message if none of the other reasons fails or if no detailed error reporting is implemented. | *
		public final static int MAV_CMD_ACK_ERR_ACCESS_DENIED=3; //, * The system is refusing to accept this command from this source 
		public final static int MAV_CMD_ACK_ERR_NOT_SUPPORTED=4; //, * Command or mission item is not supported, other commands would be accepted. | *
		public final static int MAV_CMD_ACK_ERR_COORDINATE_FRAME_NOT_SUPPORTED=5; //, * The coordinate frame of this command 
		public final static int MAV_CMD_ACK_ERR_COORDINATES_OUT_OF_RANGE=6; //, * The coordinate frame of this command is ok, but he coordinate values exceed the safety limits of this system. This is a generic error, please use the more specific error messages below if possible. | *
		public final static int MAV_CMD_ACK_ERR_X_LAT_OUT_OF_RANGE=7; //, * The X or latitude value is out of range. | *
		public final static int MAV_CMD_ACK_ERR_Y_LON_OUT_OF_RANGE=8; //, * The Y or longitude value is out of range. | *
		public final static int MAV_CMD_ACK_ERR_Z_ALT_OUT_OF_RANGE=9; //, * The Z or altitude value is out of range. | *
		public final static int MAV_CMD_ACK_ENUM_END=10; //, *  | *
	}
	//http://arducam-osd.googlecode.com/svn-history/r492/trunk/libraries/GCS_MAVLink/include/mavlink/v1.0/ardupilotmega/ardupilotmega.h
	public class MAV_CMD{
		public final static int MAV_CMD_NAV_RETURN_TO_LAUNCH=20;
		public final static int MAV_CMD_NAV_WAYPOINT=16;
		public final static int MAV_CMD_COMPONENT_ARM_DISARM=400;	
		public final static int MAV_CMD_DO_SET_HOME=179;
		public final static int MAV_CMD_NAV_LAND= 21;
		public final static int 		MAV_CMD_MISSION_START=300;
		public final static int 		MAV_CMD_DO_SET_MODE=176;
		


	}


	public static String get_MAV_CMD(int cmd){
		switch(cmd)
		{
		case JMAVLink.MAV_CMD.MAV_CMD_DO_SET_HOME:
			return "MAV_CMD_DO_SET_HOME";
		case JMAVLink.MAV_CMD.MAV_CMD_NAV_RETURN_TO_LAUNCH:
			return "MAV_CMD_NAV_RETURN_TO_LAUNCH";	
			
		case JMAVLink.MAV_CMD.MAV_CMD_COMPONENT_ARM_DISARM:
			return "MAV_CMD_COMPONENT_ARM_DISARM";
		}

		return "";
	}
	
	
	public class MAV_VAR{
		public final static int MAV_VAR_FLOAT=0; //, * 32 bit float | *
		public final static int MAV_VAR_UINT8=1; //, * 8 bit unsigned integer | *
		public final static int MAV_VAR_INT8=2; //, * 8 bit signed integer | *
		public final static int MAV_VAR_UINT16=3; //, * 16 bit unsigned integer | *
		public final static int MAV_VAR_INT16=4; //, * 16 bit signed integer | *
		public final static int MAV_VAR_UINT32=5; //, * 32 bit unsigned integer | *
		public final static int MAV_VAR_INT32=6; //, * 32 bit signed integer | *
		public final static int MAV_VAR_ENUM_END=7; //, *  | *
	}

	public class MAV_RESULT{
		public final static int MAV_RESULT_ACCEPTED=0; //, * Command ACCEPTED and EXECUTED | *
		public final static int MAV_RESULT_TEMPORARILY_REJECTED=1; //, * Command TEMPORARY REJECTED
		public final static int MAV_RESULT_DENIED=2; //, * Command PERMANENTLY DENIED | *
		public final static int MAV_RESULT_UNSUPPORTED=3; //, * Command UNKNOWN
		public final static int MAV_RESULT_FAILED=4; //, * Command executed, but failed | *
		public final static int MAV_RESULT_ENUM_END=5; //, *  | *
	}
	
	
	public static String get_MAV_RESULT(int cmd){
		switch(cmd)
		{
		case JMAVLink.MAV_RESULT.MAV_RESULT_ACCEPTED:
			return "MAV_RESULT_ACCEPTED";
		case JMAVLink.MAV_RESULT.MAV_RESULT_TEMPORARILY_REJECTED:
			return "MAV_RESULT_TEMPORARILY_REJECTED";
		case JMAVLink.MAV_RESULT.MAV_RESULT_DENIED:
			return "MAV_RESULT_DENIED";
		case JMAVLink.MAV_RESULT.MAV_RESULT_UNSUPPORTED:
			return "MAV_RESULT_UNSUPPORTED";
		case JMAVLink.MAV_RESULT.MAV_RESULT_FAILED:
			return "MAV_RESULT_FAILED";
		case JMAVLink.MAV_RESULT.MAV_RESULT_ENUM_END:
			return "MAV_RESULT_ENUM_END";
			

	}
		return "";
		}
	
	

	public class MAV_MISSION_RESULT{
		public final static int MAV_MISSION_ACCEPTED=0; //, * mission accepted OK | *
		public final static int MAV_MISSION_ERROR=1; //, * generic error 
		public final static int MAV_MISSION_UNSUPPORTED_FRAME=2; //, * coordinate frame is not supported | *
		public final static int MAV_MISSION_UNSUPPORTED=3; //, * command is not supported | *
		public final static int MAV_MISSION_NO_SPACE=4; //, * mission item exceeds storage space | *
		public final static int MAV_MISSION_INVALID=5; //, * one of the parameters has an invalid value | *
		public final static int MAV_MISSION_INVALID_PARAM1=6; //, * param1 has an invalid value | *
		public final static int MAV_MISSION_INVALID_PARAM2=7; //, * param2 has an invalid value | *
		public final static int MAV_MISSION_INVALID_PARAM3=8; //, * param3 has an invalid value | *
		public final static int MAV_MISSION_INVALID_PARAM4=9; //, * param4 has an invalid value | *
		public final static int MAV_MISSION_INVALID_PARAM5_X=10; //, * x
		public final static int MAV_MISSION_INVALID_PARAM6_Y=11; //, * y
		public final static int MAV_MISSION_INVALID_PARAM7=12; //, * param7 has an invalid value | *
		public final static int MAV_MISSION_INVALID_SEQUENCE=13; //, * received waypoint out of sequence | *
		public final static int MAV_MISSION_DENIED=14; //, * not accepting any mission commands from this communication partner | *
		public final static int MAV_MISSION_RESULT_ENUM_END=15; //, *  | *
	}
	
	public static String getMAV_MISSION_RESULT(int i){
		switch(i){
		case MAV_MISSION_RESULT.MAV_MISSION_ACCEPTED : return "MAV_MISSION_ACCEPTED";
		case MAV_MISSION_RESULT.MAV_MISSION_ERROR : return "MAV_MISSION_ERROR";
		case MAV_MISSION_RESULT.MAV_MISSION_UNSUPPORTED_FRAME : return "MAV_MISSION_UNSUPPORTED_FRAME";
		case MAV_MISSION_RESULT.MAV_MISSION_UNSUPPORTED : return "MAV_MISSION_UNSUPPORTED";
		case MAV_MISSION_RESULT.MAV_MISSION_NO_SPACE : return "MAV_MISSION_NO_SPACE";
		case MAV_MISSION_RESULT.MAV_MISSION_INVALID : return "MAV_MISSION_INVALID";
		case MAV_MISSION_RESULT.MAV_MISSION_INVALID_SEQUENCE : return "MAV_MISSION_INVALID_SEQUENCE";
		case MAV_MISSION_RESULT.MAV_MISSION_DENIED : return "MAV_MISSION_DENIED";
		case MAV_MISSION_RESULT.MAV_MISSION_RESULT_ENUM_END : return "MAV_MISSION_RESULT_ENUM_END";
		}
	return "";	
	}

	public class MAV_ACTION{
		public final static int    MAV_ACTION_HOLD = 0; //,
		public final static int    MAV_ACTION_MOTORS_START = 1; //,
		public final static int    MAV_ACTION_LAUNCH = 2; //,
		public final static int    MAV_ACTION_RETURN = 3; //,
		public final static int    MAV_ACTION_EMCY_LAND = 4; //,
		public final static int    MAV_ACTION_EMCY_KILL = 5; //,
		public final static int    MAV_ACTION_CONFIRM_KILL = 6; //,
		public final static int    MAV_ACTION_CONTINUE = 7; //,
		public final static int    MAV_ACTION_MOTORS_STOP = 8; //,
		public final static int    MAV_ACTION_HALT = 9; //,
		public final static int    MAV_ACTION_SHUTDOWN = 10; //,
		public final static int    MAV_ACTION_REBOOT = 11; //,
		public final static int    MAV_ACTION_SET_MANUAL = 12; //,
		public final static int    MAV_ACTION_SET_AUTO = 13; //,
		public final static int    MAV_ACTION_STORAGE_READ = 14; //,
		public final static int    MAV_ACTION_STORAGE_WRITE = 15; //,
		public final static int    MAV_ACTION_CALIBRATE_RC = 16; //,
		public final static int    MAV_ACTION_CALIBRATE_GYRO = 17; //,
		public final static int    MAV_ACTION_CALIBRATE_MAG = 18; //,
		public final static int    MAV_ACTION_CALIBRATE_ACC = 19; //,
		public final static int    MAV_ACTION_CALIBRATE_PRESSURE = 20; //,
		public final static int    MAV_ACTION_REC_START = 21; //,
		public final static int    MAV_ACTION_REC_PAUSE = 22; //,
		public final static int    MAV_ACTION_REC_STOP = 23; //,
		public final static int    MAV_ACTION_TAKEOFF = 24; //,
		public final static int    MAV_ACTION_NAVIGATE = 25; //,
		public final static int    MAV_ACTION_LAND = 26; //,
		public final static int    MAV_ACTION_LOITER = 27; //,
		public final static int    MAV_ACTION_SET_ORIGIN = 28; //,
		public final static int    MAV_ACTION_RELAY_ON = 29; //,
		public final static int    MAV_ACTION_RELAY_OFF = 30; //,
		public final static int    MAV_ACTION_GET_IMAGE = 31; //,
		public final static int    MAV_ACTION_VIDEO_START = 32; //,
		public final static int    MAV_ACTION_VIDEO_STOP = 33; //,
		public final static int    MAV_ACTION_RESET_MAP = 34; //,
		public final static int    MAV_ACTION_RESET_PLAN = 35; //,
		public final static int    MAV_ACTION_DELAY_BEFORE_COMMAND = 36; //,
		public final static int    MAV_ACTION_ASCEND_AT_RATE = 37; //,
		public final static int    MAV_ACTION_CHANGE_MODE = 38; //,
		public final static int    MAV_ACTION_LOITER_MAX_TURNS = 39; //,
		public final static int    MAV_ACTION_LOITER_MAX_TIME = 40; //,
		public final static int    MAV_ACTION_START_HILSIM = 41; //,
		public final static int    MAV_ACTION_STOP_HILSIM = 42; //,    
		public final static int     MAV_ACTION_NB         = 43; //
	}

	public static String getMavCmd(int a ){
		return "Needs Fixing!"; 		//return getMAVfield(MAV_CMD.class, a);

	}

	public static String getMode(int i){
		return getMAVfield(MAV_MODE.class, i);

	}

	public static String getState(int i){
		return getMAVfield(MAV_STATE.class, i);

	}

	public static String getMavFrame(int a ){
		return getMAVfield(MAV_FRAME.class, a);

	}

	//	public static String getNav(int i){
	//
	//		String s = getMAVfield(MAV_NAV.class, i);
	//		String ret = "";
	//
	//		if( !s.equals("")){
	//			s.replace("MAV_NAV_", "");
	//			ret = "MAV " + s.charAt(0);
	//
	//			s = s.substring(1);
	//			ret += s.toLowerCase();
	//
	//		}
	//
	//		return ret;
	//
	//	}
	public static String getMAVfield(Class<?> cls, int a ){
		Field[] field = cls.getFields();

		try {
			for (Field f : field) {
				if (f.getInt(null) == a)
					return f.getName();

			}
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return "" + a;
	}

}
