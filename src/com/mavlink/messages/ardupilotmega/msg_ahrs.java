package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

/**
 * Class msg_ahrs
 * Status of DCM attitude estimator
 **/
public class msg_ahrs extends IMAVLinkMessage
{

  public static final int MAVLINK_MSG_ID_AHRS = 163;
  private static final long serialVersionUID = MAVLINK_MSG_ID_AHRS;
  public msg_ahrs() {
    messageType = MAVLINK_MSG_ID_AHRS;

}

  /**
   * X gyro drift estimate rad/s
   */
  public float omegaIx;
  /**
   * Y gyro drift estimate rad/s
   */
  public float omegaIy;
  /**
   * Z gyro drift estimate rad/s
   */
  public float omegaIz;
  /**
   * average accel_weight
   */
  public float accel_weight;
  /**
   * average renormalisation value
   */
  public float renorm_val;
  /**
   * average error_roll_pitch value
   */
  public float error_rp;
  /**
   * average error_yaw value
   */
  public float error_yaw;

public String toString() {
return "MAVLINK_MSG_ID_AHRS : " +   "  omegaIx="+omegaIx+  "  omegaIy="+omegaIy+  "  omegaIz="+omegaIz+  "  accel_weight="+accel_weight+  "  renorm_val="+renorm_val+  "  error_rp="+error_rp+  "  error_yaw="+error_yaw;}
}
