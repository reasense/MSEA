package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_roll_pitch_yaw_thrust_setpoint extends IMAVLinkMessage{

	public msg_roll_pitch_yaw_thrust_setpoint(){ messageType = MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT; }

	public static final int MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT = 58;

	private static final long serialVersionUID = MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT;

	public long time_boot_ms; ///< Timestamp in milliseconds since system boot
	public float roll; ///< Desired roll angle in radians
	public float pitch; ///< Desired pitch angle in radians
	public float yaw; ///< Desired yaw angle in radians
	public float thrust; ///< Collective thrust, normalized to 0 .. 1

}