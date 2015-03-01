package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_safety_set_allowed_area extends IMAVLinkMessage{

	public msg_safety_set_allowed_area(){ messageType = MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA; }

	public static final int MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA = 54;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA;

	public float p1x; ///< x position 1 / Latitude 1
	public float p1y; ///< y position 1 / Longitude 1
	public float p1z; ///< z position 1 / Altitude 1
	public float p2x; ///< x position 2 / Latitude 2
	public float p2y; ///< y position 2 / Longitude 2
	public float p2z; ///< z position 2 / Altitude 2
	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public int frame; ///< Coordinate frame, as defined by MAV_FRAME enum in mavlink_types.h. Can be either global, GPS, right-handed with Z axis up or local, right handed, Z axis down.

}