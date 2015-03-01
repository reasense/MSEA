package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_hil_state extends IMAVLinkMessage{

	public msg_hil_state(){ messageType = MAVLINK_MSG_ID_HIL_STATE; }

	public static final int MAVLINK_MSG_ID_HIL_STATE = 90;

	private static final long serialVersionUID = MAVLINK_MSG_ID_HIL_STATE;

	public long time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public float roll; ///< Roll angle (rad)
	public float pitch; ///< Pitch angle (rad)
	public float yaw; ///< Yaw angle (rad)
	public float rollspeed; ///< Roll angular speed (rad/s)
	public float pitchspeed; ///< Pitch angular speed (rad/s)
	public float yawspeed; ///< Yaw angular speed (rad/s)
	public long lat; ///< Latitude, expressed as * 1E7
	public long lon; ///< Longitude, expressed as * 1E7
	public long alt; ///< Altitude in meters, expressed as * 1000 (millimeters)
	public int vx; ///< Ground X Speed (Latitude), expressed as m/s * 100
	public int vy; ///< Ground Y Speed (Longitude), expressed as m/s * 100
	public int vz; ///< Ground Z Speed (Altitude), expressed as m/s * 100
	public int xacc; ///< X acceleration (mg)
	public int yacc; ///< Y acceleration (mg)
	public int zacc; ///< Z acceleration (mg)

}