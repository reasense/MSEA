/**
 * Generated class : msg_vision_speed_estimate
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;



/**
 * Class msg_vision_speed_estimate
 * 
 **/
public class msg_vision_speed_estimate extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE = 103;
  private static final long serialVersionUID = MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE;
  public msg_vision_speed_estimate() {
    messageType = MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE;
}

  /**
   * Timestamp (milliseconds)
   */
  public long usec;
  /**
   * Global X speed
   */
  public float x;
  /**
   * Global Y speed
   */
  public float y;
  /**
   * Global Z speed
   */
  public float z;

}
