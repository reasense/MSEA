package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_system_time_utc extends IMAVLinkMessage{

	public msg_system_time_utc(){ messageType = MAVLINK_MSG_ID_SYSTEM_TIME_UTC; }

	public static final int MAVLINK_MSG_ID_SYSTEM_TIME_UTC = 4;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SYSTEM_TIME_UTC;

	public long utc_date; ///< GPS UTC date ddmmyy
	public long utc_time; ///< GPS UTC time hhmmss

}