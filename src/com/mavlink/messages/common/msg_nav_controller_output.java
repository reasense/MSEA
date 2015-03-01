package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_nav_controller_output extends IMAVLinkMessage{

	public msg_nav_controller_output(){ messageType = MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT; }

	public static final int MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT = 62;

	private static final long serialVersionUID = MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT;

	public float nav_roll; ///< Current desired roll in degrees
	public float nav_pitch; ///< Current desired pitch in degrees
	public float alt_error; ///< Current altitude error in meters
	public float aspd_error; ///< Current airspeed error in meters/second
	public float xtrack_error; ///< Current crosstrack error on x-y plane in meters
	public int nav_bearing; ///< Current desired heading in degrees
	public int target_bearing; ///< Bearing to current MISSION/target in degrees
	public int wp_dist; ///< Distance to active MISSION in meters

}