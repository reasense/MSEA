package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_change_operator_control extends IMAVLinkMessage{

	public msg_change_operator_control(){ messageType = MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL; }

	public static final int MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL = 5;

	private static final long serialVersionUID = MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL;

	public int target_system; ///< System the GCS requests control for
	public int control_request; ///< 0: request control of this MAV, 1: Release control of this MAV
	public int version; ///< 0: key as plaintext, 1-255: future, different hashing/encryption variants. The GCS should in general use the safest mode possible initially and then gradually move down the encryption level if it gets a NACK message indicating an encryption mismatch.
	public 	char[] passkey = new char[25];///< Password / Key, depending on version plaintext or encrypted. 25 or less characters, NULL terminated. The characters may involve A-Z, a-z, 0-9, and "!?,.-"

}