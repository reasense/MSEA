/**
 * Generated class : msg_mission_item_reached
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_mission_item_reached
 * A certain mission item has been reached. The system will either hold this position (or circle on the orbit) or (if the autocontinue on the WP was set) continue to the next MISSION.
 **/
public class msg_mission_item_reached extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_ITEM_REACHED = 46;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_ITEM_REACHED;
  public msg_mission_item_reached() {
    messageType = MAVLINK_MSG_ID_MISSION_ITEM_REACHED;

}

  /**
   * Sequence
   */
  public int seq;

}
