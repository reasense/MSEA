package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mission_request extends IMAVLinkMessage{

	public msg_mission_request(){ messageType = MAVLINK_MSG_ID_MISSION_REQUEST; }
	
	  public static final int MAVLINK_MSG_ID_MISSION_REQUEST = 40;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_REQUEST;
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
