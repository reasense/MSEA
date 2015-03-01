package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

/**
 * Class msg_mission_set_current
 * Set the mission item with sequence number seq as current item. This means that the MAV will continue to this mission item on the shortest path (not following the mission items in-between).
 **/
public class msg_mission_set_current extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_SET_CURRENT = 41;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_SET_CURRENT;
  public msg_mission_set_current() {
    messageType = MAVLINK_MSG_ID_MISSION_SET_CURRENT;

}

  /**
   * Sequence
   */
  public int seq;
  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;

}
