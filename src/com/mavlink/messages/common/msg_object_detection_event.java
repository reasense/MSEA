package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_object_detection_event extends IMAVLinkMessage{

	public msg_object_detection_event(){ messageType = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT; }

	public static final int MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT = 140;

	private static final long serialVersionUID = MAVLINK_MSG_ID_OBJECT_DETECTION_EVENT;

	public long time; ///< Timestamp in milliseconds since system boot
	public int object_id; ///< Object ID
	public int type; ///< Object type: 0: image, 1: letter, 2: ground vehicle, 3: air vehicle, 4: surface vehicle, 5: sub-surface vehicle, 6: human, 7: animal
	public 	char[] name = new char[20];///< Name of the object as defined by the detector
	public int quality; ///< Detection quality / confidence. 0: bad, 255: maximum confidence
	public float bearing; ///< Angle of the object with respect to the body frame in NED coordinates in radians. 0: front
	public float distance; ///< Ground distance in meters

}