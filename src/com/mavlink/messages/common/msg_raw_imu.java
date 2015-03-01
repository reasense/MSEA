package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_raw_imu extends IMAVLinkMessage{

	public msg_raw_imu(){ messageType = MAVLINK_MSG_ID_RAW_IMU; }

	public static final int MAVLINK_MSG_ID_RAW_IMU = 27;

	private static final long serialVersionUID = MAVLINK_MSG_ID_RAW_IMU;

	public long time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public int xacc; ///< X acceleration (raw)
	public int yacc; ///< Y acceleration (raw)
	public int zacc; ///< Z acceleration (raw)
	public int xgyro; ///< Angular speed around X axis (raw)
	public int ygyro; ///< Angular speed around Y axis (raw)
	public int zgyro; ///< Angular speed around Z axis (raw)
	public int xmag; ///< X Magnetic field (raw)
	public int ymag; ///< Y Magnetic field (raw)
	public int zmag; ///< Z Magnetic field (raw)

}