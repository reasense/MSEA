package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_global_position extends IMAVLinkMessage{

	public msg_global_position(){ messageType = MAVLINK_MSG_ID_GLOBAL_POSITION; }

	public static final int MAVLINK_MSG_ID_GLOBAL_POSITION = 33;

	private static final long serialVersionUID = MAVLINK_MSG_ID_GLOBAL_POSITION;

	public long usec; ///< Timestamp (microseconds since unix epoch)
	public float lat; ///< Latitude, in degrees
	public float lon; ///< Longitude, in degrees
	public float alt; ///< Absolute altitude, in meters
	public float vx; ///< X Speed (in Latitude direction, positive: going north)
	public float vy; ///< Y Speed (in Longitude direction, positive: going east)
	public float vz; ///< Z Speed (in Altitude direction, positive: going up)

}