/**
 * Generated class : msg_memory_vect
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_memory_vect
 * Send raw controller memory. The use of this message is discouraged for normal packets, but a quite efficient way for testing new messages and getting experimental debug output.
 **/
public class msg_memory_vect extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_MEMORY_VECT = 249;
  private static final long serialVersionUID = MAVLINK_MSG_ID_MEMORY_VECT;
  public msg_memory_vect() {
    messageType = MAVLINK_MSG_ID_MEMORY_VECT;

}

  /**
   * Starting address of the debug variables
   */
  public int address;
  /**
   * Version code of the type variable. 0=unknown, type ignored and assumed int16_t. 1=as below
   */
  public int ver;
  /**
   * Type code of the memory variables. for ver = 1: 0=16 x int16_t, 1=16 x uint16_t, 2=16 x Q15, 3=16 x 1Q14
   */
  public int type;
  /**
   * Memory contents at specified address
   */
  public int[] value = new int[32];

}
