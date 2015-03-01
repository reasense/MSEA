package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_data16
 * Data packet, size 16
 **/
public class msg_data16 extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_DATA16 = 169;
  private static final long serialVersionUID = MAVLINK_MSG_ID_DATA16;
  public msg_data16() {
    messageType = MAVLINK_MSG_ID_DATA16;
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
  public int[] data = new int[16];

public String toString() {
return "MAVLINK_MSG_ID_DATA16 : " +   "  type="+type+  "  len="+len+  "  data="+data;}
}
