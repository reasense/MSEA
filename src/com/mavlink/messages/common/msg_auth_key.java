package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_auth_key extends IMAVLinkMessage{

	public msg_auth_key(){ messageType = MAVLINK_MSG_ID_AUTH_KEY; }

	public static final int MAVLINK_MSG_ID_AUTH_KEY = 7;

	private static final long serialVersionUID = MAVLINK_MSG_ID_AUTH_KEY;

	public 	char[] key = new char[32];///< key

}