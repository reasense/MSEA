package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_manual_control extends IMAVLinkMessage{

	public msg_manual_control(){ messageType = MAVLINK_MSG_ID_MANUAL_CONTROL; }

	public static final int MAVLINK_MSG_ID_MANUAL_CONTROL = 69;

	private static final long serialVersionUID = MAVLINK_MSG_ID_MANUAL_CONTROL;

	public float roll; ///< roll
	public float pitch; ///< pitch
	public float yaw; ///< yaw
	public float thrust; ///< thrust
	public int target; ///< The system to be controlled
	public int roll_manual; ///< roll control enabled auto:0, manual:1
	public int pitch_manual; ///< pitch auto:0, manual:1
	public int yaw_manual; ///< yaw auto:0, manual:1
	public int thrust_manual; ///< thrust auto:0, manual:1

}