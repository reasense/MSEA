package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_set_roll_pitch_yaw_speed_thrust extends IMAVLinkMessage{

	public msg_set_roll_pitch_yaw_speed_thrust(){ messageType = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_SPEED_THRUST; }

	public static final int MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_SPEED_THRUST = 57;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_SPEED_THRUST;

	public float roll_speed; ///< Desired roll angular speed in rad/s
	public float pitch_speed; ///< Desired pitch angular speed in rad/s
	public float yaw_speed; ///< Desired yaw angular speed in rad/s
	public float thrust; ///< Collective thrust, normalized to 0 .. 1
	public int target_system; ///< System ID
	public int target_component; ///< Component ID

}