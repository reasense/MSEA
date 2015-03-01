package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_data96 extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_DATA96 = 172;
  private static final long serialVersionUID = MAVLINK_MSG_ID_DATA96;
  public msg_data96() {
    messageType = MAVLINK_MSG_ID_DATA96;

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
  public int[] data = new int[96];

public String toString() {
return "MAVLINK_MSG_ID_DATA96 : " +   "  type="+type+  "  len="+len+  "  data="+data;}
}
