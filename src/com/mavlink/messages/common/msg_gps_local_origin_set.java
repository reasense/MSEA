package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_gps_local_origin_set extends IMAVLinkMessage{

	public msg_gps_local_origin_set(){ messageType = MAVLINK_MSG_ID_GPS_LOCAL_ORIGIN_SET; }

	public static final int MAVLINK_MSG_ID_GPS_LOCAL_ORIGIN_SET = 49;

	private static final long serialVersionUID = MAVLINK_MSG_ID_GPS_LOCAL_ORIGIN_SET;

	public long latitude; ///< Latitude (WGS84), expressed as * 1E7
	public long longitude; ///< Longitude (WGS84), expressed as * 1E7
	public long altitude; ///< Altitude(WGS84), expressed as * 1000

}