//source : copter-gcs
	case MAVLINK_MSG_ID_HEARTBEAT:
		pack_msg_heartbeat(env, heartbeat_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SYS_STATUS:
		pack_msg_sys_status(env, sys_status_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SYSTEM_TIME:
		pack_msg_system_time(env, system_time_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_PING:
		pack_msg_ping(env, ping_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL:
		pack_msg_change_operator_control(env, change_operator_control_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_CHANGE_OPERATOR_CONTROL_ACK:
		pack_msg_change_operator_control_ack(env, change_operator_control_ack_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_AUTH_KEY:
		pack_msg_auth_key(env, auth_key_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_MODE:
		pack_msg_set_mode(env, set_mode_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_PARAM_REQUEST_READ:
		pack_msg_param_request_read(env, param_request_read_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_PARAM_REQUEST_LIST:
		pack_msg_param_request_list(env, param_request_list_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_PARAM_VALUE:
		pack_msg_param_value(env, param_value_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_PARAM_SET:
		pack_msg_param_set(env, param_set_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GPS_RAW_INT:
		pack_msg_gps_raw_int(env, gps_raw_int_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GPS_STATUS:
		pack_msg_gps_status(env, gps_status_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SCALED_IMU:
		pack_msg_scaled_imu(env, scaled_imu_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_RAW_IMU:
		pack_msg_raw_imu(env, raw_imu_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_RAW_PRESSURE:
		pack_msg_raw_pressure(env, raw_pressure_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SCALED_PRESSURE:
		pack_msg_scaled_pressure(env, scaled_pressure_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_ATTITUDE:
		pack_msg_attitude(env, attitude_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_ATTITUDE_QUATERNION:
		pack_msg_attitude_quaternion(env, attitude_quaternion_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_LOCAL_POSITION_NED:
		pack_msg_local_position_ned(env, local_position_ned_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GLOBAL_POSITION_INT:
		pack_msg_global_position_int(env, global_position_int_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_RC_CHANNELS_SCALED:
		pack_msg_rc_channels_scaled(env, rc_channels_scaled_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_RC_CHANNELS_RAW:
		pack_msg_rc_channels_raw(env, rc_channels_raw_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SERVO_OUTPUT_RAW:
		pack_msg_servo_output_raw(env, servo_output_raw_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_REQUEST_PARTIAL_LIST:
		pack_msg_mission_request_partial_list(env, mission_request_partial_list_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_WRITE_PARTIAL_LIST:
		pack_msg_mission_write_partial_list(env, mission_write_partial_list_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_ITEM:
		pack_msg_mission_item(env, mission_item_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_REQUEST:
		pack_msg_mission_request(env, mission_request_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_SET_CURRENT:
		pack_msg_mission_set_current(env, mission_set_current_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_CURRENT:
		pack_msg_mission_current(env, mission_current_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_REQUEST_LIST:
		pack_msg_mission_request_list(env, mission_request_list_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_COUNT:
		pack_msg_mission_count(env, mission_count_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_CLEAR_ALL:
		pack_msg_mission_clear_all(env, mission_clear_all_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_ITEM_REACHED:
		pack_msg_mission_item_reached(env, mission_item_reached_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MISSION_ACK:
		pack_msg_mission_ack(env, mission_ack_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_GPS_GLOBAL_ORIGIN:
		pack_msg_set_gps_global_origin(env, set_gps_global_origin_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GPS_GLOBAL_ORIGIN:
		pack_msg_gps_global_origin(env, gps_global_origin_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_LOCAL_POSITION_SETPOINT:
		pack_msg_set_local_position_setpoint(env, set_local_position_setpoint_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_LOCAL_POSITION_SETPOINT:
		pack_msg_local_position_setpoint(env, local_position_setpoint_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GLOBAL_POSITION_SETPOINT_INT:
		pack_msg_global_position_setpoint_int(env, global_position_setpoint_int_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_GLOBAL_POSITION_SETPOINT_INT:
		pack_msg_set_global_position_setpoint_int(env, set_global_position_setpoint_int_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SAFETY_SET_ALLOWED_AREA:
		pack_msg_safety_set_allowed_area(env, safety_set_allowed_area_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SAFETY_ALLOWED_AREA:
		pack_msg_safety_allowed_area(env, safety_allowed_area_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_THRUST:
		pack_msg_set_roll_pitch_yaw_thrust(env, set_roll_pitch_yaw_thrust_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_ROLL_PITCH_YAW_SPEED_THRUST:
		pack_msg_set_roll_pitch_yaw_speed_thrust(env, set_roll_pitch_yaw_speed_thrust_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_ROLL_PITCH_YAW_THRUST_SETPOINT:
		pack_msg_roll_pitch_yaw_thrust_setpoint(env, roll_pitch_yaw_thrust_setpoint_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_ROLL_PITCH_YAW_SPEED_THRUST_SETPOINT:
		pack_msg_roll_pitch_yaw_speed_thrust_setpoint(env, roll_pitch_yaw_speed_thrust_setpoint_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_NAV_CONTROLLER_OUTPUT:
		pack_msg_nav_controller_output(env, nav_controller_output_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_STATE_CORRECTION:
		pack_msg_state_correction(env, state_correction_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_REQUEST_DATA_STREAM:
		pack_msg_request_data_stream(env, request_data_stream_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_DATA_STREAM:
		pack_msg_data_stream(env, data_stream_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MANUAL_CONTROL:
		pack_msg_manual_control(env, manual_control_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_RC_CHANNELS_OVERRIDE:
		pack_msg_rc_channels_override(env, rc_channels_override_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_VFR_HUD:
		pack_msg_vfr_hud(env, vfr_hud_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_COMMAND_LONG:
		pack_msg_command_long(env, command_long_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_COMMAND_ACK:
		pack_msg_command_ack(env, command_ack_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_HIL_STATE:
		pack_msg_hil_state(env, hil_state_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_HIL_CONTROLS:
		pack_msg_hil_controls(env, hil_controls_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_HIL_RC_INPUTS_RAW:
		pack_msg_hil_rc_inputs_raw(env, hil_rc_inputs_raw_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_OPTICAL_FLOW:
		pack_msg_optical_flow(env, optical_flow_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_GLOBAL_VISION_POSITION_ESTIMATE:
		pack_msg_global_vision_position_estimate(env, global_vision_position_estimate_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_VISION_POSITION_ESTIMATE:
		pack_msg_vision_position_estimate(env, vision_position_estimate_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_VISION_SPEED_ESTIMATE:
		pack_msg_vision_speed_estimate(env, vision_speed_estimate_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_VICON_POSITION_ESTIMATE:
		pack_msg_vicon_position_estimate(env, vicon_position_estimate_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MEMORY_VECT:
		pack_msg_memory_vect(env, memory_vect_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_DEBUG_VECT:
		pack_msg_debug_vect(env, debug_vect_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_NAMED_VALUE_FLOAT:
		pack_msg_named_value_float(env, named_value_float_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_NAMED_VALUE_INT:
		pack_msg_named_value_int(env, named_value_int_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_STATUSTEXT:
		pack_msg_statustext(env, statustext_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_DEBUG:
		pack_msg_debug(env, debug_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_EXTENDED_MESSAGE:
		pack_msg_extended_message(env, extended_message_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SENSOR_OFFSETS:
		pack_msg_sensor_offsets(env, sensor_offsets_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SET_MAG_OFFSETS:
		pack_msg_set_mag_offsets(env, set_mag_offsets_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MEMINFO:
		pack_msg_meminfo(env, meminfo_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_AP_ADC:
		pack_msg_ap_adc(env, ap_adc_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_DIGICAM_CONFIGURE:
		pack_msg_digicam_configure(env, digicam_configure_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_DIGICAM_CONTROL:
		pack_msg_digicam_control(env, digicam_control_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MOUNT_CONFIGURE:
		pack_msg_mount_configure(env, mount_configure_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MOUNT_CONTROL:
		pack_msg_mount_control(env, mount_control_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_MOUNT_STATUS:
		pack_msg_mount_status(env, mount_status_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_FENCE_POINT:
		pack_msg_fence_point(env, fence_point_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_FENCE_FETCH_POINT:
		pack_msg_fence_fetch_point(env, fence_fetch_point_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_FENCE_STATUS:
		pack_msg_fence_status(env, fence_status_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_AHRS:
		pack_msg_ahrs(env, ahrs_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_SIMSTATE:
		pack_msg_simstate(env, simstate_class, obj, msg); 

		parsed=true;
		break;
	case MAVLINK_MSG_ID_HWSTATUS:
		pack_msg_hwstatus(env, hwstatus_class, obj, msg); 

		parsed=true;
		break;
