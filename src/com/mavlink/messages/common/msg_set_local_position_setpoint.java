/**
 * Generated class : msg_set_local_position_setpoint
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_set_local_position_setpoint
 * Set the setpoint for a local position controller. This is the position in local coordinates the MAV should fly to. This message is sent by the path/MISSION planner to the onboard position controller. As some MAVs have a degree of freedom in yaw (e.g. all helicopters/quadrotors), the desired yaw angle is part of the message.
 **/
public class msg_set_local_position_setpoint extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT = 50;
  private static final long serialVersionUID = MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT;
  public msg_set_local_position_setpoint() {
    messageType = MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT;

}

  /**
   * x position
   */
  public float x;
  /**
   * y position
   */
  public float y;
  /**
   * z position
   */
  public float z;
  /**
   * Desired yaw angle
   */
  public float yaw;
  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;
  /**
   * Coordinate frame - valid values are only MAV_FRAME_LOCAL_NED or MAV_FRAME_LOCAL_ENU
   */
  public int coordinate_frame;

}
