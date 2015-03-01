package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_roll_pitch_yaw_speed_thrust_setpoint extends IMAVLinkMessage{

	public msg_roll_pitch_yaw_speed_thrust_setpoint(){ messageType = MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT; }

	public static final int MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT = 59;

	private static final long serialVersionUID = MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT;

	public long time_boot_ms; ///< Timestamp in milliseconds since system boot
	public float roll_speed; ///< Desired roll angular speed in rad/s
	public float pitch_speed; ///< Desired pitch angular speed in rad/s
	public float yaw_speed; ///< Desired yaw angular speed in rad/s
	public float thrust; ///< Collective thrust, normalized to 0 .. 1

}