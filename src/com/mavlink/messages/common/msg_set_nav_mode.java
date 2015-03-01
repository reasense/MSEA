package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_set_nav_mode extends IMAVLinkMessage{

	public msg_set_nav_mode(){ messageType = MAVLINK_MSG_ID_SET_NAV_MODE; }

	public static final int MAVLINK_MSG_ID_SET_NAV_MODE = 12;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SET_NAV_MODE;

	public int target; ///< The system setting the mode
	public int nav_mode; ///< The new navigation mode

}