/**
 * Generated class : msg_gps_global_origin
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_gps_global_origin
 * Once the MAV sets a new GPS-Local correspondence, this message announces the origin (0,0,0) position
 **/
public class msg_gps_global_origin extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN = 49;
  private static final long serialVersionUID = MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;
  public msg_gps_global_origin() {
    messageType = MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN;

}

  /**
   * Latitude (WGS84), expressed as * 1E7
   */
  public long latitude;
  /**
   * Longitude (WGS84), expressed as * 1E7
   */
  public long longitude;
  /**
   * Altitude(WGS84), expressed as * 1000
   */
  public long altitude;

}
