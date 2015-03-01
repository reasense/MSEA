/**
 * Generated class : msg_vicon_position_estimate
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_vicon_position_estimate
 * 
 **/
public class msg_vicon_position_estimate extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE = 104;
  private static final long serialVersionUID = MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE;
  public msg_vicon_position_estimate() {
    messageType = MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE;
}

  /**
   * Timestamp (milliseconds)
   */
  public long usec;
  /**
   * Global X position
   */
  public float x;
  /**
   * Global Y position
   */
  public float y;
  /**
   * Global Z position
   */
  public float z;
  /**
   * Roll angle in rad
   */
  public float roll;
  /**
   * Pitch angle in rad
   */
  public float pitch;
  /**
   * Yaw angle in rad
   */
  public float yaw;

}
