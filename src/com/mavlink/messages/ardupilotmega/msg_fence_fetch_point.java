package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_fence_fetch_point
 * Request a current fence point from MAV
 **/
public class msg_fence_fetch_point extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_FENCE_FETCH_POINT = 161;
  private static final long serialVersionUID = MAVLINK_MSG_ID_FENCE_FETCH_POINT;
  public msg_fence_fetch_point() {
    messageType = MAVLINK_MSG_ID_FENCE_FETCH_POINT;

}

  /**
   * System ID
   */
  public int target_system;
  /**
   * Component ID
   */
  public int target_component;
  /**
   * point index (first point is 1, 0 is for return point)
   */
  public int idx;


}
