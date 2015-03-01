package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_local_position extends IMAVLinkMessage{

	public msg_local_position(){ messageType = MAVLINK_MSG_ID_LOCAL_POSITION; }

	public static final int MAVLINK_MSG_ID_LOCAL_POSITION = 31;

	private static final long serialVersionUID = MAVLINK_MSG_ID_LOCAL_POSITION;

	public long usec; ///< Timestamp (microseconds since UNIX epoch or microseconds since system boot)
	public float x; ///< X Position
	public float y; ///< Y Position
	public float z; ///< Z Position
	public float vx; ///< X Speed
	public float vy; ///< Y Speed
	public float vz; ///< Z Speed

}