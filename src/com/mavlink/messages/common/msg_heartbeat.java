package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_heartbeat extends IMAVLinkMessage{

	public msg_heartbeat(){ messageType = MAVLINK_MSG_ID_HEARTBEAT; }

	public static final int MAVLINK_MSG_ID_HEARTBEAT = 0;

	private static final long serialVersionUID = MAVLINK_MSG_ID_HEARTBEAT;

	public long custom_mode; ///< Navigation mode bitfield, see MAV_AUTOPILOT_CUSTOM_MODE ENUM for some examples. This field is autopilot-specific.
	public int type; ///< Type of the MAV (quadrotor, helicopter, etc., up to 15 types, defined in MAV_TYPE ENUM)
	public int autopilot; ///< Autopilot type / class. defined in MAV_CLASS ENUM
	public int base_mode; ///< System mode bitfield, see MAV_MODE_FLAGS ENUM in mavlink/include/mavlink_types.h
	public int system_status; ///< System status flag, see MAV_STATUS ENUM
	public int mavlink_version; ///< MAVLink version

}