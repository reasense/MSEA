package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_state_correction extends IMAVLinkMessage{

	public msg_state_correction(){ messageType = MAVLINK_MSG_ID_STATE_CORRECTION; }

	public static final int MAVLINK_MSG_ID_STATE_CORRECTION = 64;

	private static final long serialVersionUID = MAVLINK_MSG_ID_STATE_CORRECTION;

	public float xErr; ///< x position error
	public float yErr; ///< y position error
	public float zErr; ///< z position error
	public float rollErr; ///< roll error (radians)
	public float pitchErr; ///< pitch error (radians)
	public float yawErr; ///< yaw error (radians)
	public float vxErr; ///< x velocity
	public float vyErr; ///< y velocity
	public float vzErr; ///< z velocity

}