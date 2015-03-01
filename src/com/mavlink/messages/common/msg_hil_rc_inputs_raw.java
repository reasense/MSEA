/**
 * Generated class : msg_hil_rc_inputs_raw
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_hil_rc_inputs_raw
 * Sent from simulation to autopilot. The RAW values of the RC channels received. The standard PPM modulation is as follows: 1000 microseconds: 0%, 2000 microseconds: 100%. Individual receivers/transmitters might violate this specification.
 **/
public class msg_hil_rc_inputs_raw extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW = 92;
  private static final long serialVersionUID = MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW;
  public msg_hil_rc_inputs_raw() {
    messageType = MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW;

}

  /**
   * Timestamp (microseconds since UNIX epoch or microseconds since system boot)
   */
  public long time_usec;
  /**
   * RC channel 1 value, in microseconds
   */
  public int chan1_raw;
  /**
   * RC channel 2 value, in microseconds
   */
  public int chan2_raw;
  /**
   * RC channel 3 value, in microseconds
   */
  public int chan3_raw;
  /**
   * RC channel 4 value, in microseconds
   */
  public int chan4_raw;
  /**
   * RC channel 5 value, in microseconds
   */
  public int chan5_raw;
  /**
   * RC channel 6 value, in microseconds
   */
  public int chan6_raw;
  /**
   * RC channel 7 value, in microseconds
   */
  public int chan7_raw;
  /**
   * RC channel 8 value, in microseconds
   */
  public int chan8_raw;
  /**
   * RC channel 9 value, in microseconds
   */
  public int chan9_raw;
  /**
   * RC channel 10 value, in microseconds
   */
  public int chan10_raw;
  /**
   * RC channel 11 value, in microseconds
   */
  public int chan11_raw;
  /**
   * RC channel 12 value, in microseconds
   */
  public int chan12_raw;
  /**
   * Receive signal strength indicator, 0: 0%, 255: 100%
   */
  public int rssi;

}
