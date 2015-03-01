package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_raw_pressure extends IMAVLinkMessage{

	public msg_raw_pressure(){ messageType = MAVLINK_MSG_ID_RAW_PRESSURE; }

	public static final int MAVLINK_MSG_ID_RAW_PRESSURE = 28;

	private static final long serialVersionUID = MAVLINK_MSG_ID_RAW_PRESSURE;

	public long time_usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public int press_abs; ///< Absolute pressure (raw)
	public int press_diff1; ///< Differential pressure 1 (raw)
	public int press_diff2; ///< Differential pressure 2 (raw)
	public int temperature; ///< Raw Temperature measurement (raw)

}