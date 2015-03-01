package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_ping extends IMAVLinkMessage{

	public msg_ping(){ messageType = MAVLINK_MSG_ID_PING; }

	public static final int MAVLINK_MSG_ID_PING = 4;

	private static final long serialVersionUID = MAVLINK_MSG_ID_PING;

	public long time_usec; ///< Unix timestamp in microseconds
	public long seq; ///< PING sequence
	public int target_system; ///< 0: request ping from all receiving systems, if greater than 0: message is a ping response and number is the system id of the requesting system
	public int target_component; ///< 0: request ping from all receiving components, if greater than 0: message is a ping response and number is the system id of the requesting system

}