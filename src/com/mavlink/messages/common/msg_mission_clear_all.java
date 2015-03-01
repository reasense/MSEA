/**
 * Generated class : msg_mission_clear_all
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_mission_clear_all
 * Delete all mission items at once.
 **/
public class msg_mission_clear_all extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MISSION_CLEAR_ALL = 45;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_CLEAR_ALL;
  public msg_mission_clear_all() {
    messageType = MAVLINK_MSG_ID_MISSION_CLEAR_ALL;

}

  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;

}
