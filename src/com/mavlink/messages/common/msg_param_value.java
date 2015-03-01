package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_param_value extends IMAVLinkMessage{

	public msg_param_value(){ messageType = MAVLINK_MSG_ID_PARAM_VALUE; }

	public static final int MAVLINK_MSG_ID_PARAM_VALUE = 22;

	private static final long serialVersionUID = MAVLINK_MSG_ID_PARAM_VALUE;

	public float param_value; ///< Onboard parameter value
	public int param_count; ///< Total number of onboard parameters
	public int param_index; ///< Index of this onboard parameter
	public 	char[] param_id = new char[16];///< Onboard parameter id
	public int param_type; ///< Onboard parameter type: see MAV_VAR enum

}