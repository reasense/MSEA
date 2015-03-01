package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_set_roll_pitch_yaw_thrust extends IMAVLinkMessage{

	public msg_set_roll_pitch_yaw_thrust(){ messageType = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST; }

	public static final int MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST = 56;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST;

	public float roll; ///< Desired roll angle in radians
	public float pitch; ///< Desired pitch angle in radians
	public float yaw; ///< Desired yaw angle in radians
	public float thrust; ///< Collective thrust, normalized to 0 .. 1
	public int target_system; ///< System ID
	public int target_component; ///< Component ID

}