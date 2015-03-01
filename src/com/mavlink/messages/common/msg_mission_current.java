/**
 * Generated class : msg_mission_current
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;


import com.mavlink.messages.IMAVLinkMessage;

/**
 * Class msg_mission_current
 * Message that announces the sequence number of the current active mission item. The MAV will fly towards this mission item.
 **/
public class msg_mission_current extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_CURRENT = 42;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_CURRENT;
  public msg_mission_current() {
    messageType = MAVLINK_MSG_ID_MISSION_CURRENT;
}

  /**
   * Sequence
   */
  public int seq;

}
