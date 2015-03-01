package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;



/**
 * Class msg_data64
 * Data packet, size 64
 **/
public class msg_data64 extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_DATA64 = 171;
  private static final long serialVersionUID = MAVLINK_MSG_ID_DATA64;
  public msg_data64() {
    messageType = MAVLINK_MSG_ID_DATA64;

}

  /**
   * data type
   */
  public int type;
  /**
   * data length
   */
  public int len;
  /**
   * raw data
   */
  public int[] data = new int[64];


public String toString() {
return "MAVLINK_MSG_ID_DATA64 : " +   "  type="+type+  "  len="+len+  "  data="+data;}
}
