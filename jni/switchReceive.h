//source : copter-gcs
	case MAVLINK_MSG_ID_HEARTBEAT:
		result = unpack_msg_heartbeat(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_SYS_STATUS:
		result = unpack_msg_sys_status(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_SYSTEM_TIME:
		result = unpack_msg_system_time(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_PING:
		result = unpack_msg_ping(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL:
		result = unpack_msg_change_operator_control(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK:
		result = unpack_msg_change_operator_control_ack(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_AUTH_KEY:
		result = unpack_msg_auth_key(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_SET_MODE:
		result = unpack_msg_set_mode(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_PARAM_REQUEST_READ:
		result = unpack_msg_param_request_read(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_PARAM_REQUEST_LIST:
		result = unpack_msg_param_request_list(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_PARAM_VALUE:
		result = unpack_msg_param_value(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_PARAM_SET:
		result = unpack_msg_param_set(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_GPS_RAW_INT:
		result = unpack_msg_gps_raw_int(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_GPS_STATUS:
		result = unpack_msg_gps_status(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_SCALED_IMU:
		result = unpack_msg_scaled_imu(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_RAW_IMU:
		result = unpack_msg_raw_imu(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_RAW_PRESSURE:
		result = unpack_msg_raw_pressure(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_SCALED_PRESSURE:
		result = unpack_msg_scaled_pressure(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_ATTITUDE:
		result = unpack_msg_attitude(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_ATTITUDE_QUATERNION:
		result = unpack_msg_attitude_quaternion(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
		result = unpack_msg_local_position_ned(env, message);	
		fire_msg(result);
		break;

	case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
		result = unpack_msg_global_position_int(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:
		result = unpack_msg_rc_channels_scaled(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
		result = unpack_msg_rc_channels_raw(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
		result = unpack_msg_servo_output_raw(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST:
		result = unpack_msg_mission_request_partial_list(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST:
		result = unpack_msg_mission_write_partial_list(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_ITEM:
		result = unpack_msg_mission_item(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_REQUEST:
		result = unpack_msg_mission_request(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_SET_CURRENT:
		result = unpack_msg_mission_set_current(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_CURRENT:
		result = unpack_msg_mission_current(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
		result = unpack_msg_mission_request_list(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_COUNT:
		result = unpack_msg_mission_count(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_CLEAR_ALL:
		result = unpack_msg_mission_clear_all(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
		result = unpack_msg_mission_item_reached(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MISSION_ACK:
		result = unpack_msg_mission_ack(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN:
		result = unpack_msg_set_gps_global_origin(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN:
		result = unpack_msg_gps_global_origin(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT:
		result = unpack_msg_set_local_position_setpoint(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT:
		result = unpack_msg_local_position_setpoint(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_GLOBAL_POSITION_SETPOINT_INT:
		result = unpack_msg_global_position_setpoint_int(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_GLOBAL_POSITION_SETPOINT_INT:
		result = unpack_msg_set_global_position_setpoint_int(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA:
		result = unpack_msg_safety_set_allowed_area(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA:
		result = unpack_msg_safety_allowed_area(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST:
		result = unpack_msg_set_roll_pitch_yaw_thrust(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_SPEED_THRUST:
		result = unpack_msg_set_roll_pitch_yaw_speed_thrust(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT:
		result = unpack_msg_roll_pitch_yaw_thrust_setpoint(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT:
		result = unpack_msg_roll_pitch_yaw_speed_thrust_setpoint(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT:
		result = unpack_msg_nav_controller_output(env, message);
		fire_msg(result);

		break;

	case MAVLINK_MSG_ID_STATE_CORRECTION:
		result = unpack_msg_state_correction(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_REQUEST_DATA_STREAM:
		result = unpack_msg_request_data_stream(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_DATA_STREAM:
		result = unpack_msg_data_stream(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MANUAL_CONTROL:
		result = unpack_msg_manual_control(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:
		result = unpack_msg_rc_channels_override(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_VFR_HUD:
		result = unpack_msg_vfr_hud(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_COMMAND_LONG:
		result = unpack_msg_command_long(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_COMMAND_ACK:
		result = unpack_msg_command_ack(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_HIL_STATE:
		result = unpack_msg_hil_state(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_HIL_CONTROLS:
		result = unpack_msg_hil_controls(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW:
		result = unpack_msg_hil_rc_inputs_raw(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_OPTICAL_FLOW:
		result = unpack_msg_optical_flow(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE:
		result = unpack_msg_global_vision_position_estimate(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE:
		result = unpack_msg_vision_position_estimate(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE:
		result = unpack_msg_vision_speed_estimate(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:
		result = unpack_msg_vicon_position_estimate(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MEMORY_VECT:
		result = unpack_msg_memory_vect(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_DEBUG_VECT:
		result = unpack_msg_debug_vect(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT:
		result = unpack_msg_named_value_float(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_NAMED_VALUE_INT:
		result = unpack_msg_named_value_int(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_STATUSTEXT:
		result = unpack_msg_statustext(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_DEBUG:
		result = unpack_msg_debug(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_EXTENDED_MESSAGE:
		result = unpack_msg_extended_message(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SENSOR_OFFSETS:
		result = unpack_msg_sensor_offsets(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SET_MAG_OFFSETS:
		result = unpack_msg_set_mag_offsets(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MEMINFO:
		result = unpack_msg_meminfo(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_AP_ADC:
		result = unpack_msg_ap_adc(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_DIGICAM_CONFIGURE:
		result = unpack_msg_digicam_configure(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_DIGICAM_CONTROL:
		result = unpack_msg_digicam_control(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MOUNT_CONFIGURE:
		result = unpack_msg_mount_configure(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MOUNT_CONTROL:
		result = unpack_msg_mount_control(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_MOUNT_STATUS:
		result = unpack_msg_mount_status(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_FENCE_POINT:
		result = unpack_msg_fence_point(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_FENCE_FETCH_POINT:
		result = unpack_msg_fence_fetch_point(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_FENCE_STATUS:
		result = unpack_msg_fence_status(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_AHRS:
		result = unpack_msg_ahrs(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_SIMSTATE:
		result = unpack_msg_simstate(env, message);	
		fire_msg(result); break;

	case MAVLINK_MSG_ID_HWSTATUS:
		result = unpack_msg_hwstatus(env, message);	
		fire_msg(result); break;

