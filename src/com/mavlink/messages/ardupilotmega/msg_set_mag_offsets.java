package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_set_mag_offsets extends IMAVLinkMessage{

	public msg_set_mag_offsets(){ messageType = MAVLINK_MSG_ID_SET_MAG_OFFSETS; }

	public static final int MAVLINK_MSG_ID_SET_MAG_OFFSETS = 151;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SET_MAG_OFFSETS;

	public int mag_ofs_x; ///< magnetometer X offset
	public int mag_ofs_y; ///< magnetometer Y offset
	public int mag_ofs_z; ///< magnetometer Z offset
	public int target_system; ///< System ID
	public int target_component; ///< Component ID

}