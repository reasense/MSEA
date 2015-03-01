package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_vfr_hud extends IMAVLinkMessage{

	public msg_vfr_hud(){ messageType = MAVLINK_MSG_ID_VFR_HUD; }

	public static final int MAVLINK_MSG_ID_VFR_HUD = 74;

	private static final long serialVersionUID = MAVLINK_MSG_ID_VFR_HUD;

	public float airspeed; ///< Current airspeed in m/s
	public float groundspeed; ///< Current ground speed in m/s
	public float alt; ///< Current altitude (MSL), in meters
	public float climb; ///< Current climb rate in meters/second
	public int heading; ///< Current heading in degrees, in compass units (0..360, 0=north)
	public int throttle; ///< Current throttle setting in integer percent, 0 to 100

}