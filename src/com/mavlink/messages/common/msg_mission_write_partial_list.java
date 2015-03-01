package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mission_write_partial_list extends IMAVLinkMessage{
	  public static final int MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST = 38;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST;
	  
	  
		public msg_mission_write_partial_list(){ messageType = MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST; }
		
		  /**
		   * Start index, 0 by default and smaller / equal to the largest index of the current onboard list.
		   */
		  public int start_index;
		  /**
		   * End index, equal or greater than start index.
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
