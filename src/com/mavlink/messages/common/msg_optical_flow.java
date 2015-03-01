package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_optical_flow extends IMAVLinkMessage{

	public msg_optical_flow(){ messageType = MAVLINK_MSG_ID_OPTICAL_FLOW; }

	public static final int MAVLINK_MSG_ID_OPTICAL_FLOW = 100;

	private static final long serialVersionUID = MAVLINK_MSG_ID_OPTICAL_FLOW;

	public long time_usec; ///< Timestamp (UNIX)
	public float ground_distance; ///< Ground distance in meters
	public int flow_x; ///< Flow in pixels in x-sensor direction
	public int flow_y; ///< Flow in pixels in y-sensor direction
	public int sensor_id; ///< Sensor ID
	public int quality; ///< Optical flow quality / confidence. 0: bad, 255: maximum quality

}