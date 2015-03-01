package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_change_operator_control_ack extends IMAVLinkMessage{

	public msg_change_operator_control_ack(){ messageType = MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK; }

	public static final int MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK = 6;

	private static final long serialVersionUID = MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK;

	public int gcs_system_id; ///< ID of the GCS this message
	public int control_request; ///< 0: request control of this MAV, 1: Release control of this MAV
	public int ack; ///< 0: ACK, 1: NACK: Wrong passkey, 2: NACK: Unsupported passkey encryption method, 3: NACK: Already under control

}