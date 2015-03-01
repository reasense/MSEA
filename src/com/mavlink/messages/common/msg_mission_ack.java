/**
 * Generated class : msg_mission_ack
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_mission_ack
 * Ack message during MISSION handling. The type field states if this message is a positive ack (type=0) or if an error happened (type=non-zero).
 **/
public class msg_mission_ack extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_ACK = 47;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_ACK;
  public msg_mission_ack() {
    messageType = MAVLINK_MSG_ID_MISSION_ACK;

}

  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;
  /**
   * See MAV_MISSION_RESULT enum
   */
  public int type;

}
