package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_mission_item extends IMAVLinkMessage{
	  public static final int MAVLINK_MSG_ID_MISSION_ITEM = 39;
	  private static final long serialVersionUID = MAVLINK_MSG_ID_MISSION_ITEM;
	public msg_mission_item(){ messageType = MAVLINK_MSG_ID_MISSION_ITEM; }
	
	
	/**
	   * PARAM1 / For NAV command MISSIONs: Radius in which the MISSION is accepted as reached, in meters
	   */
	  public float param1;
	  /**
	   * PARAM2 / For NAV command MISSIONs: Time that the MAV should stay inside the PARAM1 radius before advancing, in milliseconds
	   */
	  public float param2;
	  /**
	   * PARAM3 / For LOITER command MISSIONs: Orbit to circle around the MISSION, in meters. If positive the orbit direction should be clockwise, if negative the orbit direction should be counter-clockwise.
	   */
	  public float param3;
	  /**
	   * PARAM4 / For NAV and LOITER command MISSIONs: Yaw orientation in degrees, [0..360] 0 = NORTH
	   */
	  public float param4;
	  /**
	   * PARAM5 / local: x position, global: latitude
	   */
	  public float x;
	  /**
	   * PARAM6 / y position: global: longitude
	   */
	  public float y;
	  /**
	   * PARAM7 / z position: global: altitude
	   */
	  public float z;
	  /**
	   * Sequence
	   */
	  public int seq;
	  /**
	   * The scheduled action for the MISSION. see MAV_CMD in common.xml MAVLink specs
	   */
	  public int command;
	  /**
	   * System ID
	   */
	  public int target_system;
	  /**
	   * Component ID
	   */
	  public int target_component;
	  /**
	   * The coordinate system of the MISSION. see MAV_FRAME in mavlink_types.h
	   */
	  public int frame;
	  /**
	   * false:0, true:1
	   */
	  public int current;
	  /**
	   * autocontinue to next wp
	   */
	  public int autocontinue;

}
