package com.mavlink.messages.ardupilotmega;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_sensor_offsets extends IMAVLinkMessage{

	public msg_sensor_offsets(){ messageType = MAVLINK_MSG_ID_SENSOR_OFFSETS; }

	public static final int MAVLINK_MSG_ID_SENSOR_OFFSETS = 150;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SENSOR_OFFSETS;

	public float mag_declination; ///< magnetic declination (radians)
	public long raw_press; ///< raw pressure from barometer
	public long raw_temp; ///< raw temperature from barometer
	public float gyro_cal_x; ///< gyro X calibration
	public float gyro_cal_y; ///< gyro Y calibration
	public float gyro_cal_z; ///< gyro Z calibration
	public float accel_cal_x; ///< accel X calibration
	public float accel_cal_y; ///< accel Y calibration
	public float accel_cal_z; ///< accel Z calibration
	public int mag_ofs_x; ///< magnetometer X offset
	public int mag_ofs_y; ///< magnetometer Y offset
	public int mag_ofs_z; ///< magnetometer Z offset

}