package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;



/**
 * Class msg_data32
 * Data packet, size 32
 **/
public class msg_data32 extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_DATA32 = 170;
  private static final long serialVersionUID = MAVLINK_MSG_ID_DATA32;
  public msg_data32() {
    messageType = MAVLINK_MSG_ID_DATA32;

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
  public int[] data = new int[32];

public String toString() {
return "MAVLINK_MSG_ID_DATA32 : " +   "  type="+type+  "  len="+len+  "  data="+data;}
}
