/**
 * Generated class : msg_set_gps_global_origin
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_set_gps_global_origin
 * As local MISSIONs exist, the global MISSION reference allows to transform between the local coordinate frame and the global (GPS) coordinate frame. This can be necessary when e.g. in- and outdoor settings are connected and the MAV should move from in- to outdoor.
 **/
public class msg_set_gps_global_origin extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN = 48;
  private static final long serialVersionUID = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;
  public msg_set_gps_global_origin() {
    messageType = MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN;

}

  /**
   * global position * 1E7
   */
  public long latitude;
  /**
   * global position * 1E7
   */
  public long longitude;
  /**
   * global position * 1000
   */
  public long altitude;
  /**
   * System ID
   */
  public int target_system;

}
