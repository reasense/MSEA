/**
 * Generated class : msg_extended_message
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_extended_message
 * Extended message spacer.
 **/
public class msg_extended_message extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_EXTENDED_MESSAGE = 255;
  private static final long serialVersionUID = MAVLINK_MSG_ID_EXTENDED_MESSAGE;
  public msg_extended_message() {
    messageType = MAVLINK_MSG_ID_EXTENDED_MESSAGE;
}

  /**
   * System which should execute the command
   */
  public int target_system;
  /**
   * Component which should execute the command, 0 for all components
   */
  public int target_component;
  /**
   * Retransmission / ACK flags
   */
  public int protocol_flags;
/**
 * Decode message with raw data
 */

}
