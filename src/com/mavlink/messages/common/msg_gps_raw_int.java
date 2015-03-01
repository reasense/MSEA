package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_gps_raw_int extends IMAVLinkMessage{

	public msg_gps_raw_int(){ messageType = MAVLINK_MSG_ID_GPS_RAW_INT; }

	public static final int MAVLINK_MSG_ID_GPS_RAW_INT = 24;

	private static final long serialVersionUID = MAVLINK_MSG_ID_GPS_RAW_INT;

	public long time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public long lat; ///< Latitude in 1E7 degrees
	public long lon; ///< Longitude in 1E7 degrees
	public long alt; ///< Altitude in 1E3 meters (millimeters) above MSL
	public int eph; ///< GPS HDOP horizontal dilution of position in cm (m*100). If unknown, set to: 65535
	public int epv; ///< GPS VDOP horizontal dilution of position in cm (m*100). If unknown, set to: 65535
	public int vel; ///< GPS ground speed (m/s * 100). If unknown, set to: 65535
	public int cog; ///< Course over ground (NOT heading, but direction of movement) in degrees * 100, 0.0..359.99 degrees. If unknown, set to: 65535
	public int fix_type; ///< 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.
	public int satellites_visible; ///< Number of satellites visible. If unknown, set to 255

}