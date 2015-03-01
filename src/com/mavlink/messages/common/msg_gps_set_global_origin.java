package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_gps_set_global_origin extends IMAVLinkMessage{

	public msg_gps_set_global_origin(){ messageType = MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN; }

	public static final int MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN = 48;

	private static final long serialVersionUID = MAVLINK_MSG_ID_GPS_SET_GLOBAL_ORIGIN;

	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public long latitude; ///< global position * 1E7
	public long longitude; ///< global position * 1E7
	public long altitude; ///< global position * 1000

}