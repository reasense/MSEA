package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_local_position_setpoint_set extends IMAVLinkMessage{

	public msg_local_position_setpoint_set(){ messageType = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT_SET; }

	public static final int MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT_SET = 50;

	private static final long serialVersionUID = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT_SET;

	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public float x; ///< x position
	public float y; ///< y position
	public float z; ///< z position
	public float yaw; ///< Desired yaw angle

}