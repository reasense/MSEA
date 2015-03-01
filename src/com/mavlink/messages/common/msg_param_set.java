package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_param_set extends IMAVLinkMessage{

	public msg_param_set(){ messageType = MAVLINK_MSG_ID_PARAM_SET; }

	public static final int MAVLINK_MSG_ID_PARAM_SET = 23;

	private static final long serialVersionUID = MAVLINK_MSG_ID_PARAM_SET;

	public float param_value; ///< Onboard parameter value
	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public 	char[] param_id = new char[16];///< Onboard parameter id
	public int param_type; ///< Onboard parameter type: see MAV_VAR enum

}