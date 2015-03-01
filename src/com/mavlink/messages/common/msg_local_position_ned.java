package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_local_position_ned extends IMAVLinkMessage{
	  public static final int MAVLINK_MSG_ID_LOCAL_POSITION_NED = 32;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_LOCAL_POSITION_NED;
	  
		public msg_local_position_ned(){ messageType = MAVLINK_MSG_ID_LOCAL_POSITION_NED; }
		 /**
		   * Timestamp (milliseconds since system boot)
		   */
		  public long time_boot_ms;
		  /**
		   * X Position
		   */
		  public float x;
		  /**
		   * Y Position
		   */
		  public float y;
		  /**
		   * Z Position
		   */
		  public float z;
		  /**
		   * X Speed
		   */
		  public float vx;
		  /**
		   * Y Speed
		   */
		  public float vy;
		  /**
		   * Z Speed
		   */
		  public float vz;

}
