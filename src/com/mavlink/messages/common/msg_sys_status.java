package com.mavlink.messages.common;

import com.mavlink.messages.IMAVLinkMessage;

public class msg_sys_status extends IMAVLinkMessage{

	public msg_sys_status(){ messageType = MAVLINK_MSG_ID_SYS_STATUS; }

	public static final int MAVLINK_MSG_ID_SYS_STATUS = 1;

	private static final long serialVersionUID = MAVLINK_MSG_ID_SYS_STATUS;

	public long onboard_control_sensors_present; ///< Bitmask showing which onboard controllers and sensors are present. Value of 0: not present. Value of 1: present. Indices: 0: 3D gyro, 1: 3D acc, 2: 3D mag, 3: absolute pressure, 4: differential pressure, 5: GPS, 6: optical flow, 7: computer vision position, 8: laser based position, 9: external ground-truth (Vicon or Leica). Controllers: 10: 3D angular rate control 11: attitude stabilization, 12: yaw position, 13: z/altitude control, 14: x/y position control, 15: motor outputs / control
	public long onboard_control_sensors_enabled; ///< Bitmask showing which onboard controllers and sensors are enabled:  Value of 0: not enabled. Value of 1: enabled. Indices: 0: 3D gyro, 1: 3D acc, 2: 3D mag, 3: absolute pressure, 4: differential pressure, 5: GPS, 6: optical flow, 7: computer vision position, 8: laser based position, 9: external ground-truth (Vicon or Leica). Controllers: 10: 3D angular rate control 11: attitude stabilization, 12: yaw position, 13: z/altitude control, 14: x/y position control, 15: motor outputs / control
	public long onboard_control_sensors_health; ///< Bitmask showing which onboard controllers and sensors are operational or have an error:  Value of 0: not enabled. Value of 1: enabled. Indices: 0: 3D gyro, 1: 3D acc, 2: 3D mag, 3: absolute pressure, 4: differential pressure, 5: GPS, 6: optical flow, 7: computer vision position, 8: laser based position, 9: external ground-truth (Vicon or Leica). Controllers: 10: 3D angular rate control 11: attitude stabilization, 12: yaw position, 13: z/altitude control, 14: x/y position control, 15: motor outputs / control
	public int load; ///< Maximum usage in percent of the mainloop time, (0%: 0, 100%: 1000) should be always below 1000
	public int voltage_battery; ///< Battery voltage, in millivolts (1 = 1 millivolt)
	public int current_battery; ///< Battery current, in 10*milliamperes (1 = 10 milliampere), -1: autopilot does not measure the current
	public int drop_rate_comm; ///< Communication drops in percent, (0%: 0, 100%: 10'000), (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
	public int errors_comm; ///< Communication errors (UART, I2C, SPI, CAN), dropped packets on all links (packets that were corrupted on reception on the MAV)
	public int errors_count1; ///< Autopilot-specific errors
	public int errors_count2; ///< Autopilot-specific errors
	public int errors_count3; ///< Autopilot-specific errors
	public int errors_count4; ///< Autopilot-specific errors
	public int battery_remaining; ///< Remaining battery energy: (0%: 0, 100%: 100), -1: autopilot estimate the remaining battery

}