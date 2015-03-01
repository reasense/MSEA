package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_local_position_setpoint extends IMAVLinkMessage{

	public msg_local_position_setpoint(){ messageType = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT; }

	public static final int MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT = 51;

	private static final long serialVersionUID = MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT;

	public float x; ///< x position
	public float y; ///< y position
	public float z; ///< z position
	public float yaw; ///< Desired yaw angle
	public int coordinate_frame; ///< Coordinate frame - valid values are only MAV_FRAME_LOCAL_NED or MAV_FRAME_LOCAL_ENU

}