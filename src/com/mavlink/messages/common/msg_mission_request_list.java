package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

/**
 * Class msg_mission_request_list
 * Request the overall list of mission items from the system/component.
 **/
public class msg_mission_request_list extends IMAVLinkMessage {
	
  public static final int MAVLINK_MSG_ID_MISSION_REQUEST_LIST = 43;
  
  public msg_mission_request_list() {
    messageType = MAVLINK_MSG_ID_MISSION_REQUEST_LIST;
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