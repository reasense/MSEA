package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_digicam_configure extends IMAVLinkMessage{

	public msg_digicam_configure(){ messageType = MAVLINK_MSG_ID_DIGICAM_CONFIGURE; }

	public static final int MAVLINK_MSG_ID_DIGICAM_CONFIGURE = 154;

	private static final long serialVersionUID = MAVLINK_MSG_ID_DIGICAM_CONFIGURE;

	public float extra_value; ///< Correspondent value to given extra_param
	public int shutter_speed; ///< Divisor number //e.g. 1000 means 1/1000 (0 means ignore)
	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public int mode; ///< Mode enumeration from 1 to N //P, TV, AV, M, Etc (0 means ignore)
	public int aperture; ///< F stop number x 10 //e.g. 28 means 2.8 (0 means ignore)
	public int iso; ///< ISO enumeration from 1 to N //e.g. 80, 100, 200, Etc (0 means ignore)
	public int exposure_type; ///< Exposure type enumeration from 1 to N (0 means ignore)
	public int command_id; ///< Command Identity (incremental loop: 0 to 255)//A command sent multiple times will be executed or pooled just once
	public int engine_cut_off; ///< Main engine cut-off time before camera trigger in seconds/10 (0 means no cut-off)
	public int extra_param; ///< Extra parameters enumeration (0 means ignore)

}