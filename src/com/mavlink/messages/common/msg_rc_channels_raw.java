package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_rc_channels_raw extends IMAVLinkMessage{

	public msg_rc_channels_raw(){ messageType = MAVLINK_MSG_ID_RC_CHANNELS_RAW; }

	public static final int MAVLINK_MSG_ID_RC_CHANNELS_RAW = 35;

	private static final long serialVersionUID = MAVLINK_MSG_ID_RC_CHANNELS_RAW;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public int chan1_raw; ///< RC channel 1 value, in microseconds
	public int chan2_raw; ///< RC channel 2 value, in microseconds
	public int chan3_raw; ///< RC channel 3 value, in microseconds
	public int chan4_raw; ///< RC channel 4 value, in microseconds
	public int chan5_raw; ///< RC channel 5 value, in microseconds
	public int chan6_raw; ///< RC channel 6 value, in microseconds
	public int chan7_raw; ///< RC channel 7 value, in microseconds
	public int chan8_raw; ///< RC channel 8 value, in microseconds
	public int port; ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows to encode more than 8 servos.
	public int rssi; ///< Receive signal strength indicator, 0: 0%, 255: 100%

}