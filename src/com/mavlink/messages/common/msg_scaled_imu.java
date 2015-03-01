package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_scaled_imu extends IMAVLinkMessage{

	public msg_scaled_imu(){ messageType = MAVLINK_MSG_ID_SCALED_IMU; }

	public static final int MAVLINK_MSG_ID_SCALED_IMU = 26;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SCALED_IMU;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public int xacc; ///< X acceleration (mg)
	public int yacc; ///< Y acceleration (mg)
	public int zacc; ///< Z acceleration (mg)
	public int xgyro; ///< Angular speed around X axis (millirad /sec)
	public int ygyro; ///< Angular speed around Y axis (millirad /sec)
	public int zgyro; ///< Angular speed around Z axis (millirad /sec)
	public int xmag; ///< X Magnetic field (milli tesla)
	public int ymag; ///< Y Magnetic field (milli tesla)
	public int zmag; ///< Z Magnetic field (milli tesla)

}