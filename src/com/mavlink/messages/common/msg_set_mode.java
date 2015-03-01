package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_set_mode extends IMAVLinkMessage{

	public msg_set_mode(){ messageType = MAVLINK_MSG_ID_SET_MODE; }

	public static final int MAVLINK_MSG_ID_SET_MODE = 11;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SET_MODE;

	public long custom_mode; ///< The new autopilot-specific mode. This field can be ignored by an autopilot.
	public int target_system; ///< The system setting the mode
	public int base_mode; ///< The new base mode

}