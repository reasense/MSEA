/**
 * Generated class : msg_mission_count
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_mission_count
 * This message is emitted as response to MISSION_REQUEST_LIST by the MAV and to initiate a write transaction. The GCS can then request the individual mission item based on the knowledge of the total number of MISSIONs.
 **/
public class msg_mission_count extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_COUNT = 44;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_COUNT;
  public msg_mission_count() {
    messageType = MAVLINK_MSG_ID_MISSION_COUNT;

}

  /**
   * Number of mission items in the sequence
   */
  public int count;
  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;

}
