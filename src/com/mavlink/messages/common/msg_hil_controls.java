package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_hil_controls extends IMAVLinkMessage{

	public msg_hil_controls(){ messageType = MAVLINK_MSG_ID_HIL_CONTROLS; }

	public static final int MAVLINK_MSG_ID_HIL_CONTROLS = 91;

	private static final long serialVersionUID = MAVLINK_MSG_ID_HIL_CONTROLS;

	public long time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public float roll_ailerons; ///< Control output -1 .. 1
	public float pitch_elevator; ///< Control output -1 .. 1
	public float yaw_rudder; ///< Control output -1 .. 1
	public float throttle; ///< Throttle 0 .. 1
	public float aux1; ///< Aux 1, -1 .. 1
	public float aux2; ///< Aux 2, -1 .. 1
	public float aux3; ///< Aux 3, -1 .. 1
	public float aux4; ///< Aux 4, -1 .. 1
	public int mode; ///< System mode (MAV_MODE)
	public int nav_mode; ///< Navigation mode (MAV_NAV_MODE)

}