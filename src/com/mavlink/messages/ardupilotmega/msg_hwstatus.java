package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

/**
 * Class msg_hwstatus
 * Status of key hardware
 **/
public class msg_hwstatus extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_HWSTATUS = 165;
  private static final long serialVersionUID = MAVLINK_MSG_ID_HWSTATUS;
  public msg_hwstatus() {
    messageType = MAVLINK_MSG_ID_HWSTATUS;

}

  /**
   * board voltage (mV)
   */
  public int Vcc;
  /**
   * I2C error count
   */
  public int I2Cerr;

public String toString() {
return "MAVLINK_MSG_ID_HWSTATUS : " +   "  Vcc="+Vcc+  "  I2Cerr="+I2Cerr;}
}
