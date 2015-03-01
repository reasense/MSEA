package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;



/**
 * Class msg_fence_status
 * Status of geo-fencing. Sent in extended
                status stream when fencing enabled
 **/
public class msg_fence_status extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_FENCE_STATUS = 162;
  private static final long serialVersionUID = MAVLINK_MSG_ID_FENCE_STATUS;
  public msg_fence_status() {
    messageType = MAVLINK_MSG_ID_FENCE_STATUS;

}

  /**
   * time of last breach in milliseconds since boot
   */
  public long breach_time;
  /**
   * number of fence breaches
   */
  public int breach_count;
  /**
   * 0 if currently inside fence, 1 if outside
   */
  public int breach_status;
  /**
   * last breach type (see FENCE_BREACH_* enum)
   */
  public int breach_type;

}
