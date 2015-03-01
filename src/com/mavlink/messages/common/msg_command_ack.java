package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_command_ack extends IMAVLinkMessage{

	public msg_command_ack(){ messageType = MAVLINK_MSG_ID_COMMAND_ACK; }

	public static final int MAVLINK_MSG_ID_COMMAND_ACK = 77;

	private static final long serialVersionUID = MAVLINK_MSG_ID_COMMAND_ACK;

	public int command; ///< Command ID, as defined by MAV_CMD enum.
	public int result; ///< See MAV_RESULT enum

}