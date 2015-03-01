package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_limits_status
 * Status of AP_Limits. Sent in extended
	    status stream when AP_Limits is enabled
 **/
public class msg_limits_status extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_LIMITS_STATUS = 167;
  private static final long serialVersionUID = MAVLINK_MSG_ID_LIMITS_STATUS;
  public msg_limits_status() {
    messageType = MAVLINK_MSG_ID_LIMITS_STATUS;

}

  /**
   * time of last breach in milliseconds since boot
   */
  public long last_trigger;
  /**
   * time of last recovery action in milliseconds since boot
   */
  public long last_action;
  /**
   * time of last successful recovery in milliseconds since boot
   */
  public long last_recovery;
  /**
   * time of last all-clear in milliseconds since boot
   */
  public long last_clear;
  /**
   * number of fence breaches
   */
  public int breach_count;
  /**
   * state of AP_Limits, (see enum LimitState, LIMITS_STATE)
   */
  public int limits_state;
  /**
   * AP_Limit_Module bitfield of enabled modules, (see enum moduleid or LIMIT_MODULE)
   */
  public int mods_enabled;
  /**
   * AP_Limit_Module bitfield of required modules, (see enum moduleid or LIMIT_MODULE)
   */
  public int mods_required;
  /**
   * AP_Limit_Module bitfield of triggered modules, (see enum moduleid or LIMIT_MODULE)
   */
  public int mods_triggered;
/**
 * Decode message with raw data
 */

public String toString() {
return "MAVLINK_MSG_ID_LIMITS_STATUS : " +   "  last_trigger="+last_trigger+  "  last_action="+last_action+  "  last_recovery="+last_recovery+  "  last_clear="+last_clear+  "  breach_count="+breach_count+  "  limits_state="+limits_state+  "  mods_enabled="+mods_enabled+  "  mods_required="+mods_required+  "  mods_triggered="+mods_triggered;}
}
