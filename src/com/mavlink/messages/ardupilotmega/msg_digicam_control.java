package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_digicam_control extends IMAVLinkMessage{

	public msg_digicam_control(){ messageType = MAVLINK_MSG_ID_DIGICAM_CONTROL; }

	public static final int MAVLINK_MSG_ID_DIGICAM_CONTROL = 155;

	private static final long serialVersionUID = MAVLINK_MSG_ID_DIGICAM_CONTROL;

	public float extra_value; ///< Correspondent value to given extra_param
	public int target_system; ///< System ID
	public int target_component; ///< Component ID
	public int session; ///< 0: stop, 1: start or keep it up //Session control e.g. show/hide lens
	public int zoom_pos; ///< 1 to N //Zoom's absolute position (0 means ignore)
	public int zoom_step; ///< -100 to 100 //Zooming step value to offset zoom from the current position
	public int focus_lock; ///< 0: unlock focus or keep unlocked, 1: lock focus or keep locked, 3: re-lock focus
	public int shot; ///< 0: ignore, 1: shot or start filming
	public int command_id; ///< Command Identity (incremental loop: 0 to 255)//A command sent multiple times will be executed or pooled just once
	public int extra_param; ///< Extra parameters enumeration (0 means ignore)

}