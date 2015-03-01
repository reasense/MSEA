package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mount_control extends IMAVLinkMessage{

	public msg_mount_control(){ messageType = MAVLINK_MSG_ID_MOUNT_CONTROL; }

	public static final int MAVLINK_MSG_ID_MOUNT_CONTROL = 157;

	private static final long serialVersionUID = MAVLINK_MSG_ID_MOUNT_CONTROL;

	public long input_a; ///< pitch(deg*100) or lat, depending on mount mode
	public long input_b; ///< roll(deg*100) or lon depending on mount mode
	public long input_c; ///< yaw(deg*100) or alt (in cm) depending on mount mode
	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public int save_position; ///< if "1" it will save current trimmed position on EEPROM (just valid for NEUTRAL and LANDING)

}