package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;
/**
 * Class msg_fence_point
 * A fence point. Used to set a point when from
                GCS -> MAV. Also used to return a point from MAV -> GCS
 **/
public class msg_fence_point extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_FENCE_POINT = 160;
  private static final long serialVersionUID = MAVLINK_MSG_ID_FENCE_POINT;
  public msg_fence_point() {
    messageType = MAVLINK_MSG_ID_FENCE_POINT;

}

  /**
   * Latitude of point
   */
  public float lat;
  /**
   * Longitude of point
   */
  public float lng;
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
  /**
   * total number of points (for sanity checking)
   */
  public int count;

}
