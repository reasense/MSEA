package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mount_status extends IMAVLinkMessage{

	public msg_mount_status(){ messageType = MAVLINK_MSG_ID_MOUNT_STATUS; }

	public static final int MAVLINK_MSG_ID_MOUNT_STATUS = 158;

	private static final long serialVersionUID = MAVLINK_MSG_ID_MOUNT_STATUS;

	public long pointing_a; ///< pitch(deg*100) or lat, depending on mount mode
	public long pointing_b; ///< roll(deg*100) or lon depending on mount mode
	public long pointing_c; ///< yaw(deg*100) or alt (in cm) depending on mount mode
	public int target_system; ///< System ID
	public int target_component; ///< Component ID

}