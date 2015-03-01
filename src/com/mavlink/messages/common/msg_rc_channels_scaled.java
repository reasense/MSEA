package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_rc_channels_scaled extends IMAVLinkMessage{

	public msg_rc_channels_scaled(){ messageType = MAVLINK_MSG_ID_RC_CHANNELS_SCALED; }

	public static final int MAVLINK_MSG_ID_RC_CHANNELS_SCALED = 34;

	private static final long serialVersionUID = MAVLINK_MSG_ID_RC_CHANNELS_SCALED;

	public long time_boot_ms; ///< Timestamp (milliseconds since system boot)
	public int chan1_scaled; ///< RC channel 1 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan2_scaled; ///< RC channel 2 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan3_scaled; ///< RC channel 3 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan4_scaled; ///< RC channel 4 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan5_scaled; ///< RC channel 5 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan6_scaled; ///< RC channel 6 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan7_scaled; ///< RC channel 7 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int chan8_scaled; ///< RC channel 8 value scaled, (-100%) -10000, (0%) 0, (100%) 10000
	public int port; ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows to encode more than 8 servos.
	public int rssi; ///< Receive signal strength indicator, 0: 0%, 255: 100%

}