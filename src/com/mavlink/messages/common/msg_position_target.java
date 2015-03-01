package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_position_target extends IMAVLinkMessage{

	public msg_position_target(){ messageType = MAVLINK_MSG_ID_POSITION_TARGET; }

	public static final int MAVLINK_MSG_ID_POSITION_TARGET = 63;

	private static final long serialVersionUID = MAVLINK_MSG_ID_POSITION_TARGET;

	public float x; ///< x position
	public float y; ///< y position
	public float z; ///< z position
	public float yaw; ///< yaw orientation in radians, 0 = NORTH

}