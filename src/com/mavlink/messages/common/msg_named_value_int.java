package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_named_value_int extends IMAVLinkMessage{

	public msg_named_value_int(){ messageType = MAVLINK_MSG_ID_NAMED_VALUE_INT; }

	public static final int MAVLINK_MSG_ID_NAMED_VALUE_INT = 252;

	private static final long serialVersionUID = MAVLINK_MSG_ID_NAMED_VALUE_INT;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public long value; ///< Signed integer value
	public 	char[] name = new char[10];///< Name of the debug variable

}