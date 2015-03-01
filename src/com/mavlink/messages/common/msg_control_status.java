package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_control_status extends IMAVLinkMessage{

	public msg_control_status(){ messageType = MAVLINK_MSG_ID_CONTROL_STATUS; }

	public static final int MAVLINK_MSG_ID_CONTROL_STATUS = 52;

	private static final long serialVersionUID = MAVLINK_MSG_ID_CONTROL_STATUS;

	public int position_fix; ///< Position fix: 0: lost, 2: 2D position fix, 3: 3D position fix
	public int vision_fix; ///< Vision position fix: 0: lost, 1: 2D local position hold, 2: 2D global position fix, 3: 3D global position fix
	public int gps_fix; ///< GPS position fix: 0: no reception, 1: Minimum 1 satellite, but no position fix, 2: 2D position fix, 3: 3D position fix
	public int ahrs_health; ///< Attitude estimation health: 0: poor, 255: excellent
	public int control_att; ///< 0: Attitude control disabled, 1: enabled
	public int control_pos_xy; ///< 0: X, Y position control disabled, 1: enabled
	public int control_pos_z; ///< 0: Z position control disabled, 1: enabled
	public int control_pos_yaw; ///< 0: Yaw angle control disabled, 1: enabled

}