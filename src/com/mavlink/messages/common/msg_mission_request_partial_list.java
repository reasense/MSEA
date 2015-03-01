package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mission_request_partial_list extends IMAVLinkMessage{
	
	  public static final int MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST = 37;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST;
	  
	public msg_mission_request_partial_list(){ messageType = MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST; }

	
	  /**
	   * Start index, 0 by default
	   */
	  public int start_index;
	  /**
	   * End index, -1 by default (-1: send list to end). Else a valid index of the list
	   */
	  public int end_index;
	  /**
	   * System ID
	   */
	  public int target_system;
	  /**
	   * Component ID
	   */
	  public int target_component;
}
