package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_global_position_int extends IMAVLinkMessage{

	public msg_global_position_int(){ messageType = MAVLINK_MSG_ID_GLOBAL_POSITION_INT; }

	public static final int MAVLINK_MSG_ID_GLOBAL_POSITION_INT = 33;

	private static final long serialVersionUID = MAVLINK_MSG_ID_GLOBAL_POSITION_INT;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public long lat; ///< Latitude, expressed as * 1E7
	public long lon; ///< Longitude, expressed as * 1E7
	public long alt; ///< Altitude in meters, expressed as * 1000 (millimeters), above MSL
	public long relative_alt; ///< Altitude above ground in meters, expressed as * 1000 (millimeters)
	public int vx; ///< Ground X Speed (Latitude), expressed as m/s * 100
	public int vy; ///< Ground Y Speed (Longitude), expressed as m/s * 100
	public int vz; ///< Ground Z Speed (Altitude), expressed as m/s * 100
	public int hdg; ///< Compass heading in degrees * 100, 0.0..359.99 degrees. If unknown, set to: 65535

}