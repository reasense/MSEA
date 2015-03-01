package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_simstate
 * Status of simulation environment, if used
 **/
public class msg_simstate extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_SIMSTATE = 164;
  private static final long serialVersionUID = MAVLINK_MSG_ID_SIMSTATE;
  public msg_simstate() {
    messageType = MAVLINK_MSG_ID_SIMSTATE;
   
}

  /**
   * Roll angle (rad)
   */
  public float roll;
  /**
   * Pitch angle (rad)
   */
  public float pitch;
  /**
   * Yaw angle (rad)
   */
  public float yaw;
  /**
   * X acceleration m/s/s
   */
  public float xacc;
  /**
   * Y acceleration m/s/s
   */
  public float yacc;
  /**
   * Z acceleration m/s/s
   */
  public float zacc;
  /**
   * Angular speed around X axis rad/s
   */
  public float xgyro;
  /**
   * Angular speed around Y axis rad/s
   */
  public float ygyro;
  /**
   * Angular speed around Z axis rad/s
   */
  public float zgyro;
  /**
   * Latitude in degrees
   */
  public float lat;
  /**
   * Longitude in degrees
   */
  public float lng;

public String toString() {
return "MAVLINK_MSG_ID_SIMSTATE : " +   "  roll="+roll+  "  pitch="+pitch+  "  yaw="+yaw+  "  xacc="+xacc+  "  yacc="+yacc+  "  zacc="+zacc+  "  xgyro="+xgyro+  "  ygyro="+ygyro+  "  zgyro="+zgyro+  "  lat="+lat+  "  lng="+lng;}
}
