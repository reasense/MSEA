package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_command extends IMAVLinkMessage{

	public msg_command(){ messageType = MAVLINK_MSG_ID_COMMAND; }

	public static final int MAVLINK_MSG_ID_COMMAND = 75;

	private static final long serialVersionUID = MAVLINK_MSG_ID_COMMAND;

	public int target_system; ///< System which should execute the command
	public int target_component; ///< Component which should execute the command, 0 for all components
	public int command; ///< Command ID, as defined by MAV_CMD enum.
	public int confirmation; ///< 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
	public float param1; ///< Parameter 1, as defined by MAV_CMD enum.
	public float param2; ///< Parameter 2, as defined by MAV_CMD enum.
	public float param3; ///< Parameter 3, as defined by MAV_CMD enum.
	public float param4; ///< Parameter 4, as defined by MAV_CMD enum.

}