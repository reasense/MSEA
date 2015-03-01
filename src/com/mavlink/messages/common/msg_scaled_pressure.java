package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_scaled_pressure extends IMAVLinkMessage{

	public msg_scaled_pressure(){ messageType = MAVLINK_MSG_ID_SCALED_PRESSURE; }

	public static final int MAVLINK_MSG_ID_SCALED_PRESSURE = 29;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SCALED_PRESSURE;

	public long time_boot_ms; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public float press_abs; ///< Absolute pressure (hectopascal)
	public float press_diff; ///< Differential pressure 1 (hectopascal)
	public int temperature; ///< Temperature measurement (0.01 degrees celsius)

}