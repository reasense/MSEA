package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_wind
 * Wind estimation
 **/
public class msg_wind extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_WIND = 168;
  private static final long serialVersionUID = MAVLINK_MSG_ID_WIND;
  public msg_wind() {
    messageType = MAVLINK_MSG_ID_WIND;

}

  /**
   * wind direction (degrees)
   */
  public float direction;
  /**
   * wind speed in ground plane (m/s)
   */
  public float speed;
  /**
   * vertical wind speed (m/s)
   */
  public float speed_z;
/**
 * Decode message with raw data
 */

public String toString() {
return "MAVLINK_MSG_ID_WIND : " +   "  direction="+direction+  "  speed="+speed+  "  speed_z="+speed_z;}
}
