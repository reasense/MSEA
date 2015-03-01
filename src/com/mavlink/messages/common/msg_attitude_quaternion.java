package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_attitude_quaternion extends IMAVLinkMessage{
	
	
	 public static final int MAVLINK_MSG_ID_ATTITUDE_QUATERNION = 31;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_ATTITUDE_QUATERNION;
	  
	  
	public msg_attitude_quaternion(){ messageType = MAVLINK_MSG_ID_ATTITUDE_QUATERNION; }
	
	  /**
	   * Timestamp (milliseconds since system boot)
	   */
	  public long time_boot_ms;
	  /**
	   * Quaternion component 1
	   */
	  public float q1;
	  /**
	   * Quaternion component 2
	   */
	  public float q2;
	  /**
	   * Quaternion component 3
	   */
	  public float q3;
	  /**
	   * Quaternion component 4
	   */
	  public float q4;
	  /**
	   * Roll angular speed (rad/s)
	   */
	  public float rollspeed;
	  /**
	   * Pitch angular speed (rad/s)
	   */
	  public float pitchspeed;
	  /**
	   * Yaw angular speed (rad/s)
	   */
	  public float yawspeed;
	
	
}
