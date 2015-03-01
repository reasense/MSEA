/**
 * Generated class : msg_command_long
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;


/**
 * Class msg_command_long
 * Send a command with up to four parameters to the MAV
 **/
public class msg_command_long extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_COMMAND_LONG = 76;
  private static final long serialVersionUID = MAVLINK_MSG_ID_COMMAND_LONG;
  public msg_command_long() {
    messageType = MAVLINK_MSG_ID_COMMAND_LONG;
}

  /**
   * Parameter 1, as defined by MAV_CMD enum.
   */
  public float param1;
  /**
   * Parameter 2, as defined by MAV_CMD enum.
   */
  public float param2;
  /**
   * Parameter 3, as defined by MAV_CMD enum.
   */
  public float param3;
  /**
   * Parameter 4, as defined by MAV_CMD enum.
   */
  public float param4;
  /**
   * Parameter 5, as defined by MAV_CMD enum.
   */
  public float param5;
  /**
   * Parameter 6, as defined by MAV_CMD enum.
   */
  public float param6;
  /**
   * Parameter 7, as defined by MAV_CMD enum.
   */
  public float param7;
  /**
   * Command ID, as defined by MAV_CMD enum.
   */
  public int command;
  /**
   * System which should execute the command
   */
  public int target_system;
  /**
   * Component which should execute the command, 0 for all components
   */
  public int target_component;
  /**
   * 0: First transmission of this command. 1-255: Confirmation transmissions (e.g. for kill command)
   */
  public int confirmation;
/**
 * Decode message with raw data
 */

}
