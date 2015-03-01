package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_servo_output_raw extends IMAVLinkMessage{

	public msg_servo_output_raw(){ messageType = MAVLINK_MSG_ID_SERVO_OUTPUT_RAW; }

	public static final int MAVLINK_MSG_ID_SERVO_OUTPUT_RAW = 36;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SERVO_OUTPUT_RAW;

	public long time_usec; ///< Timestamp (since UNIX epoch or microseconds since system boot)
	public int servo1_raw; ///< Servo output 1 value, in microseconds
	public int servo2_raw; ///< Servo output 2 value, in microseconds
	public int servo3_raw; ///< Servo output 3 value, in microseconds
	public int servo4_raw; ///< Servo output 4 value, in microseconds
	public int servo5_raw; ///< Servo output 5 value, in microseconds
	public int servo6_raw; ///< Servo output 6 value, in microseconds
	public int servo7_raw; ///< Servo output 7 value, in microseconds
	public int servo8_raw; ///< Servo output 8 value, in microseconds
	public int port; ///< Servo output port (set of 8 outputs = 1 port). Most MAVs will just use one, but this allows to encode more than 8 servos.

}