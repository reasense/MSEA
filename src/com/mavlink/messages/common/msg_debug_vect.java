package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_debug_vect extends IMAVLinkMessage{

	public msg_debug_vect(){ messageType = MAVLINK_MSG_ID_DEBUG_VECT; }

	public static final int MAVLINK_MSG_ID_DEBUG_VECT = 250;

	private static final long serialVersionUID = MAVLINK_MSG_ID_DEBUG_VECT;

	public long time_usec; ///< Timestamp
	public float x; ///< x
	public float y; ///< y
	public float z; ///< z
	public 	char[] name = new char[10];///< Name

}