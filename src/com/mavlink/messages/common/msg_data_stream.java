/**
 * Generated class : msg_data_stream
 * DO NOT MODIFY!
 **/
package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

import java.io.ByteArrayOutputStream;
import java.io.IOException;

/**
 * Class msg_data_stream
 * 
 **/
public class msg_data_stream extends IMAVLinkMessage {
  public static final int MAVLINK_MSG_ID_DATA_STREAM = 67;
  private static final long serialVersionUID = MAVLINK_MSG_ID_DATA_STREAM;
  public msg_data_stream() {
    messageType = MAVLINK_MSG_ID_DATA_STREAM;
}

  /**
   * The requested interval between two messages of this type
   */
  public int message_rate;
  /**
   * The ID of the requested data stream
   */
  public int stream_id;
  /**
   * 1 stream is enabled, 0 stream is stopped.
   */
  public int on_off;
/**
 * Decode message with raw data
 */

}
