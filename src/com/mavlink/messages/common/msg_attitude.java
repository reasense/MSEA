package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_attitude extends IMAVLinkMessage{

	public msg_attitude(){ messageType = MAVLINK_MSG_ID_ATTITUDE; }

	public static final int MAVLINK_MSG_ID_ATTITUDE = 30;

	private static final long serialVersionUID = MAVLINK_MSG_ID_ATTITUDE;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public float roll; ///< Roll angle (rad)
	public float pitch; ///< Pitch angle (rad)
	public float yaw; ///< Yaw angle (rad)
	public float rollspeed; ///< Roll angular speed (rad/s)
	public float pitchspeed; ///< Pitch angular speed (rad/s)
	public float yawspeed; ///< Yaw angular speed (rad/s)

}