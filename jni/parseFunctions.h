//source : copter-gcs
uint8_t system_id = 255;
uint8_t component_id = 0;
jobject unpack_msg_heartbeat(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_heartbeat_t inp;
	mavlink_msg_heartbeat_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(heartbeat_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(heartbeat_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(heartbeat_class, "custom_mode", "J");
	env->SetLongField (result, fid, (long) inp.custom_mode);

	fid = env->GetFieldID(heartbeat_class, "type", "I");
	env->SetIntField (result, fid, (int) inp.type);

	fid = env->GetFieldID(heartbeat_class, "autopilot", "I");
	env->SetIntField (result, fid, (int) inp.autopilot);

	fid = env->GetFieldID(heartbeat_class, "base_mode", "I");
	env->SetIntField (result, fid, (int) inp.base_mode);

	fid = env->GetFieldID(heartbeat_class, "system_status", "I");
	env->SetIntField (result, fid, (int) inp.system_status);

	fid = env->GetFieldID(heartbeat_class, "mavlink_version", "I");
	env->SetIntField (result, fid, (int) inp.mavlink_version);


	fid = env->GetFieldID(heartbeat_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(heartbeat_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_heartbeat(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t custom_mode = (uint32_t)env->GetLongField (obj, env->GetFieldID(heartbeat_class, "custom_mode", "J"));
	uint8_t type = (uint8_t)env->GetIntField (obj, env->GetFieldID(heartbeat_class, "type", "I"));
	uint8_t autopilot = (uint8_t)env->GetIntField (obj, env->GetFieldID(heartbeat_class, "autopilot", "I"));
	uint8_t base_mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(heartbeat_class, "base_mode", "I"));
	uint8_t system_status = (uint8_t)env->GetIntField (obj, env->GetFieldID(heartbeat_class, "system_status", "I"));
	uint8_t mavlink_version = (uint8_t)env->GetIntField (obj, env->GetFieldID(heartbeat_class, "mavlink_version", "I"));


	mavlink_msg_heartbeat_pack(system_id, component_id, &msg,type, autopilot, base_mode, custom_mode, system_status);

}

jobject unpack_msg_sys_status(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_sys_status_t inp;
	mavlink_msg_sys_status_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(sys_status_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(sys_status_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(sys_status_class, "onboard_control_sensors_present", "J");
	env->SetLongField (result, fid, (long) inp.onboard_control_sensors_present);

	fid = env->GetFieldID(sys_status_class, "onboard_control_sensors_enabled", "J");
	env->SetLongField (result, fid, (long) inp.onboard_control_sensors_enabled);

	fid = env->GetFieldID(sys_status_class, "onboard_control_sensors_health", "J");
	env->SetLongField (result, fid, (long) inp.onboard_control_sensors_health);

	fid = env->GetFieldID(sys_status_class, "load", "I");
	env->SetIntField (result, fid, (int) inp.load);

	fid = env->GetFieldID(sys_status_class, "voltage_battery", "I");
	env->SetIntField (result, fid, (int) inp.voltage_battery);

	fid = env->GetFieldID(sys_status_class, "current_battery", "I");
	env->SetIntField (result, fid, (int) inp.current_battery);

	fid = env->GetFieldID(sys_status_class, "drop_rate_comm", "I");
	env->SetIntField (result, fid, (int) inp.drop_rate_comm);

	fid = env->GetFieldID(sys_status_class, "errors_comm", "I");
	env->SetIntField (result, fid, (int) inp.errors_comm);

	fid = env->GetFieldID(sys_status_class, "errors_count1", "I");
	env->SetIntField (result, fid, (int) inp.errors_count1);

	fid = env->GetFieldID(sys_status_class, "errors_count2", "I");
	env->SetIntField (result, fid, (int) inp.errors_count2);

	fid = env->GetFieldID(sys_status_class, "errors_count3", "I");
	env->SetIntField (result, fid, (int) inp.errors_count3);

	fid = env->GetFieldID(sys_status_class, "errors_count4", "I");
	env->SetIntField (result, fid, (int) inp.errors_count4);

	fid = env->GetFieldID(sys_status_class, "battery_remaining", "I");
	env->SetIntField (result, fid, (int) inp.battery_remaining);


	fid = env->GetFieldID(sys_status_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(sys_status_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_sys_status(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t onboard_control_sensors_present = (uint32_t)env->GetLongField (obj, env->GetFieldID(sys_status_class, "onboard_control_sensors_present", "J"));
	uint32_t onboard_control_sensors_enabled = (uint32_t)env->GetLongField (obj, env->GetFieldID(sys_status_class, "onboard_control_sensors_enabled", "J"));
	uint32_t onboard_control_sensors_health = (uint32_t)env->GetLongField (obj, env->GetFieldID(sys_status_class, "onboard_control_sensors_health", "J"));
	uint16_t load = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "load", "I"));
	uint16_t voltage_battery = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "voltage_battery", "I"));
	int16_t current_battery = (int16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "current_battery", "I"));
	uint16_t drop_rate_comm = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "drop_rate_comm", "I"));
	uint16_t errors_comm = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "errors_comm", "I"));
	uint16_t errors_count1 = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "errors_count1", "I"));
	uint16_t errors_count2 = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "errors_count2", "I"));
	uint16_t errors_count3 = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "errors_count3", "I"));
	uint16_t errors_count4 = (uint16_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "errors_count4", "I"));
	int8_t battery_remaining = (int8_t)env->GetIntField (obj, env->GetFieldID(sys_status_class, "battery_remaining", "I"));


	mavlink_msg_sys_status_pack(system_id, component_id, &msg,onboard_control_sensors_present, onboard_control_sensors_enabled, onboard_control_sensors_health, load, voltage_battery, current_battery, battery_remaining, drop_rate_comm, errors_comm, errors_count1, errors_count2, errors_count3, errors_count4);

}

jobject unpack_msg_system_time(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_system_time_t inp;
	mavlink_msg_system_time_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(system_time_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(system_time_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(system_time_class, "time_unix_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_unix_usec);

	fid = env->GetFieldID(system_time_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);


	fid = env->GetFieldID(system_time_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(system_time_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_system_time(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_unix_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(system_time_class, "time_unix_usec", "J"));
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(system_time_class, "time_boot_ms", "J"));


	mavlink_msg_system_time_pack(system_id, component_id, &msg,time_unix_usec, time_boot_ms);

}

jobject unpack_msg_ping(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_ping_t inp;
	mavlink_msg_ping_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(ping_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(ping_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(ping_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(ping_class, "seq", "J");
	env->SetLongField (result, fid, (long) inp.seq);

	fid = env->GetFieldID(ping_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(ping_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(ping_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(ping_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_ping(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(ping_class, "time_usec", "J"));
	uint32_t seq = (uint32_t)env->GetLongField (obj, env->GetFieldID(ping_class, "seq", "J"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(ping_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(ping_class, "target_component", "I"));


	mavlink_msg_ping_pack(system_id, component_id, &msg,time_usec, seq, target_system, target_component);

}

jobject unpack_msg_change_operator_control(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_change_operator_control_t inp;
	mavlink_msg_change_operator_control_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(change_operator_control_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(change_operator_control_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(change_operator_control_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(change_operator_control_class, "control_request", "I");
	env->SetIntField (result, fid, (int) inp.control_request);

	fid = env->GetFieldID(change_operator_control_class, "version", "I");
	env->SetIntField (result, fid, (int) inp.version);

	{
		fid = env->GetFieldID(change_operator_control_class, "passkey", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 25; i++)
			data[i] = inp.passkey[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(change_operator_control_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(change_operator_control_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_change_operator_control(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_class, "target_system", "I"));
	uint8_t control_request = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_class, "control_request", "I"));
	uint8_t version = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_class, "version", "I"));
	char passkey[25];
	{
	jfieldID fid;
		fid = env->GetFieldID(change_operator_control_class, "passkey", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 25; i++)
			passkey[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_change_operator_control_pack(system_id, component_id, &msg,target_system, control_request, version, passkey);

}

jobject unpack_msg_change_operator_control_ack(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_change_operator_control_ack_t inp;
	mavlink_msg_change_operator_control_ack_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(change_operator_control_ack_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(change_operator_control_ack_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(change_operator_control_ack_class, "gcs_system_id", "I");
	env->SetIntField (result, fid, (int) inp.gcs_system_id);

	fid = env->GetFieldID(change_operator_control_ack_class, "control_request", "I");
	env->SetIntField (result, fid, (int) inp.control_request);

	fid = env->GetFieldID(change_operator_control_ack_class, "ack", "I");
	env->SetIntField (result, fid, (int) inp.ack);


	fid = env->GetFieldID(change_operator_control_ack_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(change_operator_control_ack_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_change_operator_control_ack(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t gcs_system_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_ack_class, "gcs_system_id", "I"));
	uint8_t control_request = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_ack_class, "control_request", "I"));
	uint8_t ack = (uint8_t)env->GetIntField (obj, env->GetFieldID(change_operator_control_ack_class, "ack", "I"));


	mavlink_msg_change_operator_control_ack_pack(system_id, component_id, &msg,gcs_system_id, control_request, ack);

}

jobject unpack_msg_auth_key(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_auth_key_t inp;
	mavlink_msg_auth_key_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(auth_key_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(auth_key_class, cid);


	//Set values
	jfieldID fid;
	{
		fid = env->GetFieldID(auth_key_class, "key", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 32; i++)
			data[i] = inp.key[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(auth_key_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(auth_key_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_auth_key(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	char key[32];
	{
	jfieldID fid;
		fid = env->GetFieldID(auth_key_class, "key", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 32; i++)
			key[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_auth_key_pack(system_id, component_id, &msg,key);

}

jobject unpack_msg_set_mode(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_mode_t inp;
	mavlink_msg_set_mode_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_mode_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_mode_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_mode_class, "custom_mode", "J");
	env->SetLongField (result, fid, (long) inp.custom_mode);

	fid = env->GetFieldID(set_mode_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(set_mode_class, "base_mode", "I");
	env->SetIntField (result, fid, (int) inp.base_mode);


	fid = env->GetFieldID(set_mode_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_mode_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_mode(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t custom_mode = (uint32_t)env->GetLongField (obj, env->GetFieldID(set_mode_class, "custom_mode", "J"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_mode_class, "target_system", "I"));
	uint8_t base_mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_mode_class, "base_mode", "I"));


	mavlink_msg_set_mode_pack(system_id, component_id, &msg,target_system, base_mode, custom_mode);

}

jobject unpack_msg_param_request_read(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_param_request_read_t inp;
	mavlink_msg_param_request_read_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(param_request_read_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(param_request_read_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(param_request_read_class, "param_index", "I");
	env->SetIntField (result, fid, (int) inp.param_index);

	fid = env->GetFieldID(param_request_read_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(param_request_read_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	{
		fid = env->GetFieldID(param_request_read_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			data[i] = inp.param_id[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(param_request_read_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(param_request_read_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_param_request_read(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int16_t param_index = (int16_t)env->GetIntField (obj, env->GetFieldID(param_request_read_class, "param_index", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_request_read_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_request_read_class, "target_component", "I"));
	char param_id[16];
	{
	jfieldID fid;
		fid = env->GetFieldID(param_request_read_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			param_id[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_param_request_read_pack(system_id, component_id, &msg,target_system, target_component, param_id, param_index);

}

jobject unpack_msg_param_request_list(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_param_request_list_t inp;
	mavlink_msg_param_request_list_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(param_request_list_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(param_request_list_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(param_request_list_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(param_request_list_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(param_request_list_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(param_request_list_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_param_request_list(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_request_list_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_request_list_class, "target_component", "I"));


	mavlink_msg_param_request_list_pack(system_id, component_id, &msg,target_system, target_component);

}

jobject unpack_msg_param_value(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_param_value_t inp;
	mavlink_msg_param_value_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(param_value_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(param_value_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(param_value_class, "param_value", "F");
	env->SetFloatField (result, fid, (float)inp.param_value);

	fid = env->GetFieldID(param_value_class, "param_count", "I");
	env->SetIntField (result, fid, (int) inp.param_count);

	fid = env->GetFieldID(param_value_class, "param_index", "I");
	env->SetIntField (result, fid, (int) inp.param_index);

	{
		fid = env->GetFieldID(param_value_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			data[i] = inp.param_id[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}
	fid = env->GetFieldID(param_value_class, "param_type", "I");
	env->SetIntField (result, fid, (int) inp.param_type);


	fid = env->GetFieldID(param_value_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(param_value_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_param_value(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float param_value = (float)env->GetFloatField (obj, env->GetFieldID(param_value_class, "param_value", "F"));
	uint16_t param_count = (uint16_t)env->GetIntField (obj, env->GetFieldID(param_value_class, "param_count", "I"));
	uint16_t param_index = (uint16_t)env->GetIntField (obj, env->GetFieldID(param_value_class, "param_index", "I"));
	char param_id[16];
	{
	jfieldID fid;
		fid = env->GetFieldID(param_value_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			param_id[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}
	uint8_t param_type = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_value_class, "param_type", "I"));


	mavlink_msg_param_value_pack(system_id, component_id, &msg,param_id, param_value, param_type, param_count, param_index);

}

jobject unpack_msg_param_set(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_param_set_t inp;
	mavlink_msg_param_set_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(param_set_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(param_set_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(param_set_class, "param_value", "F");
	env->SetFloatField (result, fid, (float)inp.param_value);

	fid = env->GetFieldID(param_set_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(param_set_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	{
		fid = env->GetFieldID(param_set_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			data[i] = inp.param_id[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}
	fid = env->GetFieldID(param_set_class, "param_type", "I");
	env->SetIntField (result, fid, (int) inp.param_type);


	fid = env->GetFieldID(param_set_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(param_set_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_param_set(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float param_value = (float)env->GetFloatField (obj, env->GetFieldID(param_set_class, "param_value", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_set_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_set_class, "target_component", "I"));
	char param_id[16];
	{
	jfieldID fid;
		fid = env->GetFieldID(param_set_class, "param_id", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 16; i++)
			param_id[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}
	uint8_t param_type = (uint8_t)env->GetIntField (obj, env->GetFieldID(param_set_class, "param_type", "I"));


	mavlink_msg_param_set_pack(system_id, component_id, &msg,target_system, target_component, param_id, param_value, param_type);

}

jobject unpack_msg_gps_raw_int(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_gps_raw_int_t inp;
	mavlink_msg_gps_raw_int_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(gps_raw_int_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(gps_raw_int_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(gps_raw_int_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(gps_raw_int_class, "lat", "J");
	env->SetLongField (result, fid, (long) inp.lat);

	fid = env->GetFieldID(gps_raw_int_class, "lon", "J");
	env->SetLongField (result, fid, (long) inp.lon);

	fid = env->GetFieldID(gps_raw_int_class, "alt", "J");
	env->SetLongField (result, fid, (long) inp.alt);

	fid = env->GetFieldID(gps_raw_int_class, "eph", "I");
	env->SetIntField (result, fid, (int) inp.eph);

	fid = env->GetFieldID(gps_raw_int_class, "epv", "I");
	env->SetIntField (result, fid, (int) inp.epv);

	fid = env->GetFieldID(gps_raw_int_class, "vel", "I");
	env->SetIntField (result, fid, (int) inp.vel);

	fid = env->GetFieldID(gps_raw_int_class, "cog", "I");
	env->SetIntField (result, fid, (int) inp.cog);

	fid = env->GetFieldID(gps_raw_int_class, "fix_type", "I");
	env->SetIntField (result, fid, (int) inp.fix_type);

	fid = env->GetFieldID(gps_raw_int_class, "satellites_visible", "I");
	env->SetIntField (result, fid, (int) inp.satellites_visible);


	fid = env->GetFieldID(gps_raw_int_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(gps_raw_int_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_gps_raw_int(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(gps_raw_int_class, "time_usec", "J"));
	int32_t lat = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_raw_int_class, "lat", "J"));
	int32_t lon = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_raw_int_class, "lon", "J"));
	int32_t alt = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_raw_int_class, "alt", "J"));
	uint16_t eph = (uint16_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "eph", "I"));
	uint16_t epv = (uint16_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "epv", "I"));
	uint16_t vel = (uint16_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "vel", "I"));
	uint16_t cog = (uint16_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "cog", "I"));
	uint8_t fix_type = (uint8_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "fix_type", "I"));
	uint8_t satellites_visible = (uint8_t)env->GetIntField (obj, env->GetFieldID(gps_raw_int_class, "satellites_visible", "I"));


	mavlink_msg_gps_raw_int_pack(system_id, component_id, &msg,time_usec, fix_type, lat, lon, alt, eph, epv, vel, cog, satellites_visible);

}

jobject unpack_msg_gps_status(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_gps_status_t inp;
	mavlink_msg_gps_status_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(gps_status_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(gps_status_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(gps_status_class, "satellites_visible", "I");
	env->SetIntField (result, fid, (int) inp.satellites_visible);

	{
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_prn", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			data[i] = inp.satellite_prn[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
	{
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_used", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			data[i] = inp.satellite_used[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
	{
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_elevation", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			data[i] = inp.satellite_elevation[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
	{
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_azimuth", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			data[i] = inp.satellite_azimuth[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
	{
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_snr", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			data[i] = inp.satellite_snr[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}

	fid = env->GetFieldID(gps_status_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(gps_status_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_gps_status(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t satellites_visible = (uint8_t)env->GetIntField (obj, env->GetFieldID(gps_status_class, "satellites_visible", "I"));
uint8_t satellite_prn[20];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_prn", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			satellite_prn[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
uint8_t satellite_used[20];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_used", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			satellite_used[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
uint8_t satellite_elevation[20];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_elevation", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			satellite_elevation[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
uint8_t satellite_azimuth[20];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_azimuth", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			satellite_azimuth[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}
uint8_t satellite_snr[20];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(gps_status_class, "satellite_snr", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 20; i++)
			satellite_snr[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}


	mavlink_msg_gps_status_pack(system_id, component_id, &msg,satellites_visible, satellite_prn, satellite_used, satellite_elevation, satellite_azimuth, satellite_snr);

}

jobject unpack_msg_scaled_imu(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_scaled_imu_t inp;
	mavlink_msg_scaled_imu_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(scaled_imu_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(scaled_imu_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(scaled_imu_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(scaled_imu_class, "xacc", "I");
	env->SetIntField (result, fid, (int) inp.xacc);

	fid = env->GetFieldID(scaled_imu_class, "yacc", "I");
	env->SetIntField (result, fid, (int) inp.yacc);

	fid = env->GetFieldID(scaled_imu_class, "zacc", "I");
	env->SetIntField (result, fid, (int) inp.zacc);

	fid = env->GetFieldID(scaled_imu_class, "xgyro", "I");
	env->SetIntField (result, fid, (int) inp.xgyro);

	fid = env->GetFieldID(scaled_imu_class, "ygyro", "I");
	env->SetIntField (result, fid, (int) inp.ygyro);

	fid = env->GetFieldID(scaled_imu_class, "zgyro", "I");
	env->SetIntField (result, fid, (int) inp.zgyro);

	fid = env->GetFieldID(scaled_imu_class, "xmag", "I");
	env->SetIntField (result, fid, (int) inp.xmag);

	fid = env->GetFieldID(scaled_imu_class, "ymag", "I");
	env->SetIntField (result, fid, (int) inp.ymag);

	fid = env->GetFieldID(scaled_imu_class, "zmag", "I");
	env->SetIntField (result, fid, (int) inp.zmag);


	fid = env->GetFieldID(scaled_imu_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(scaled_imu_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_scaled_imu(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(scaled_imu_class, "time_boot_ms", "J"));
	int16_t xacc = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "xacc", "I"));
	int16_t yacc = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "yacc", "I"));
	int16_t zacc = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "zacc", "I"));
	int16_t xgyro = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "xgyro", "I"));
	int16_t ygyro = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "ygyro", "I"));
	int16_t zgyro = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "zgyro", "I"));
	int16_t xmag = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "xmag", "I"));
	int16_t ymag = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "ymag", "I"));
	int16_t zmag = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_imu_class, "zmag", "I"));


	mavlink_msg_scaled_imu_pack(system_id, component_id, &msg,time_boot_ms, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag);

}

jobject unpack_msg_raw_imu(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_raw_imu_t inp;
	mavlink_msg_raw_imu_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(raw_imu_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(raw_imu_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(raw_imu_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(raw_imu_class, "xacc", "I");
	env->SetIntField (result, fid, (int) inp.xacc);

	fid = env->GetFieldID(raw_imu_class, "yacc", "I");
	env->SetIntField (result, fid, (int) inp.yacc);

	fid = env->GetFieldID(raw_imu_class, "zacc", "I");
	env->SetIntField (result, fid, (int) inp.zacc);

	fid = env->GetFieldID(raw_imu_class, "xgyro", "I");
	env->SetIntField (result, fid, (int) inp.xgyro);

	fid = env->GetFieldID(raw_imu_class, "ygyro", "I");
	env->SetIntField (result, fid, (int) inp.ygyro);

	fid = env->GetFieldID(raw_imu_class, "zgyro", "I");
	env->SetIntField (result, fid, (int) inp.zgyro);

	fid = env->GetFieldID(raw_imu_class, "xmag", "I");
	env->SetIntField (result, fid, (int) inp.xmag);

	fid = env->GetFieldID(raw_imu_class, "ymag", "I");
	env->SetIntField (result, fid, (int) inp.ymag);

	fid = env->GetFieldID(raw_imu_class, "zmag", "I");
	env->SetIntField (result, fid, (int) inp.zmag);


	fid = env->GetFieldID(raw_imu_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(raw_imu_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_raw_imu(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(raw_imu_class, "time_usec", "J"));
	int16_t xacc = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "xacc", "I"));
	int16_t yacc = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "yacc", "I"));
	int16_t zacc = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "zacc", "I"));
	int16_t xgyro = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "xgyro", "I"));
	int16_t ygyro = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "ygyro", "I"));
	int16_t zgyro = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "zgyro", "I"));
	int16_t xmag = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "xmag", "I"));
	int16_t ymag = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "ymag", "I"));
	int16_t zmag = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_imu_class, "zmag", "I"));


	mavlink_msg_raw_imu_pack(system_id, component_id, &msg,time_usec, xacc, yacc, zacc, xgyro, ygyro, zgyro, xmag, ymag, zmag);

}

jobject unpack_msg_raw_pressure(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_raw_pressure_t inp;
	mavlink_msg_raw_pressure_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(raw_pressure_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(raw_pressure_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(raw_pressure_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(raw_pressure_class, "press_abs", "I");
	env->SetIntField (result, fid, (int) inp.press_abs);

	fid = env->GetFieldID(raw_pressure_class, "press_diff1", "I");
	env->SetIntField (result, fid, (int) inp.press_diff1);

	fid = env->GetFieldID(raw_pressure_class, "press_diff2", "I");
	env->SetIntField (result, fid, (int) inp.press_diff2);

	fid = env->GetFieldID(raw_pressure_class, "temperature", "I");
	env->SetIntField (result, fid, (int) inp.temperature);


	fid = env->GetFieldID(raw_pressure_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(raw_pressure_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_raw_pressure(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(raw_pressure_class, "time_usec", "J"));
	int16_t press_abs = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_pressure_class, "press_abs", "I"));
	int16_t press_diff1 = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_pressure_class, "press_diff1", "I"));
	int16_t press_diff2 = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_pressure_class, "press_diff2", "I"));
	int16_t temperature = (int16_t)env->GetIntField (obj, env->GetFieldID(raw_pressure_class, "temperature", "I"));


	mavlink_msg_raw_pressure_pack(system_id, component_id, &msg,time_usec, press_abs, press_diff1, press_diff2, temperature);

}

jobject unpack_msg_scaled_pressure(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_scaled_pressure_t inp;
	mavlink_msg_scaled_pressure_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(scaled_pressure_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(scaled_pressure_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(scaled_pressure_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(scaled_pressure_class, "press_abs", "F");
	env->SetFloatField (result, fid, (float)inp.press_abs);

	fid = env->GetFieldID(scaled_pressure_class, "press_diff", "F");
	env->SetFloatField (result, fid, (float)inp.press_diff);

	fid = env->GetFieldID(scaled_pressure_class, "temperature", "I");
	env->SetIntField (result, fid, (int) inp.temperature);


	fid = env->GetFieldID(scaled_pressure_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(scaled_pressure_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_scaled_pressure(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(scaled_pressure_class, "time_boot_ms", "J"));
	float press_abs = (float)env->GetFloatField (obj, env->GetFieldID(scaled_pressure_class, "press_abs", "F"));
	float press_diff = (float)env->GetFloatField (obj, env->GetFieldID(scaled_pressure_class, "press_diff", "F"));
	int16_t temperature = (int16_t)env->GetIntField (obj, env->GetFieldID(scaled_pressure_class, "temperature", "I"));


	mavlink_msg_scaled_pressure_pack(system_id, component_id, &msg,time_boot_ms, press_abs, press_diff, temperature);

}

jobject unpack_msg_attitude(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_attitude_t inp;
	mavlink_msg_attitude_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(attitude_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(attitude_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(attitude_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(attitude_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(attitude_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(attitude_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(attitude_class, "rollspeed", "F");
	env->SetFloatField (result, fid, (float)inp.rollspeed);

	fid = env->GetFieldID(attitude_class, "pitchspeed", "F");
	env->SetFloatField (result, fid, (float)inp.pitchspeed);

	fid = env->GetFieldID(attitude_class, "yawspeed", "F");
	env->SetFloatField (result, fid, (float)inp.yawspeed);


	fid = env->GetFieldID(attitude_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(attitude_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_attitude(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(attitude_class, "time_boot_ms", "J"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "yaw", "F"));
	float rollspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "rollspeed", "F"));
	float pitchspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "pitchspeed", "F"));
	float yawspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_class, "yawspeed", "F"));


	mavlink_msg_attitude_pack(system_id, component_id, &msg,time_boot_ms, roll, pitch, yaw, rollspeed, pitchspeed, yawspeed);

}

jobject unpack_msg_attitude_quaternion(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_attitude_quaternion_t inp;
	mavlink_msg_attitude_quaternion_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(attitude_quaternion_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(attitude_quaternion_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(attitude_quaternion_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(attitude_quaternion_class, "q1", "F");
	env->SetFloatField (result, fid, (float)inp.q1);

	fid = env->GetFieldID(attitude_quaternion_class, "q2", "F");
	env->SetFloatField (result, fid, (float)inp.q2);

	fid = env->GetFieldID(attitude_quaternion_class, "q3", "F");
	env->SetFloatField (result, fid, (float)inp.q3);

	fid = env->GetFieldID(attitude_quaternion_class, "q4", "F");
	env->SetFloatField (result, fid, (float)inp.q4);

	fid = env->GetFieldID(attitude_quaternion_class, "rollspeed", "F");
	env->SetFloatField (result, fid, (float)inp.rollspeed);

	fid = env->GetFieldID(attitude_quaternion_class, "pitchspeed", "F");
	env->SetFloatField (result, fid, (float)inp.pitchspeed);

	fid = env->GetFieldID(attitude_quaternion_class, "yawspeed", "F");
	env->SetFloatField (result, fid, (float)inp.yawspeed);


	fid = env->GetFieldID(attitude_quaternion_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(attitude_quaternion_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_attitude_quaternion(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(attitude_quaternion_class, "time_boot_ms", "J"));
	float q1 = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "q1", "F"));
	float q2 = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "q2", "F"));
	float q3 = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "q3", "F"));
	float q4 = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "q4", "F"));
	float rollspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "rollspeed", "F"));
	float pitchspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "pitchspeed", "F"));
	float yawspeed = (float)env->GetFloatField (obj, env->GetFieldID(attitude_quaternion_class, "yawspeed", "F"));


	mavlink_msg_attitude_quaternion_pack(system_id, component_id, &msg,time_boot_ms, q1, q2, q3, q4, rollspeed, pitchspeed, yawspeed);

}

jobject unpack_msg_local_position_ned(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_local_position_ned_t inp;
	mavlink_msg_local_position_ned_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(local_position_ned_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(local_position_ned_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(local_position_ned_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(local_position_ned_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(local_position_ned_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(local_position_ned_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(local_position_ned_class, "vx", "F");
	env->SetFloatField (result, fid, (float)inp.vx);

	fid = env->GetFieldID(local_position_ned_class, "vy", "F");
	env->SetFloatField (result, fid, (float)inp.vy);

	fid = env->GetFieldID(local_position_ned_class, "vz", "F");
	env->SetFloatField (result, fid, (float)inp.vz);


	fid = env->GetFieldID(local_position_ned_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(local_position_ned_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_local_position_ned(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(local_position_ned_class, "time_boot_ms", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "z", "F"));
	float vx = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "vx", "F"));
	float vy = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "vy", "F"));
	float vz = (float)env->GetFloatField (obj, env->GetFieldID(local_position_ned_class, "vz", "F"));


	mavlink_msg_local_position_ned_pack(system_id, component_id, &msg,time_boot_ms, x, y, z, vx, vy, vz);

}

jobject unpack_msg_global_position_int(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_global_position_int_t inp;
	mavlink_msg_global_position_int_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(global_position_int_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(global_position_int_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(global_position_int_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(global_position_int_class, "lat", "J");
	env->SetLongField (result, fid, (long) inp.lat);

	fid = env->GetFieldID(global_position_int_class, "lon", "J");
	env->SetLongField (result, fid, (long) inp.lon);

	fid = env->GetFieldID(global_position_int_class, "alt", "J");
	env->SetLongField (result, fid, (long) inp.alt);

	fid = env->GetFieldID(global_position_int_class, "relative_alt", "J");
	env->SetLongField (result, fid, (long) inp.relative_alt);

	fid = env->GetFieldID(global_position_int_class, "vx", "I");
	env->SetIntField (result, fid, (int) inp.vx);

	fid = env->GetFieldID(global_position_int_class, "vy", "I");
	env->SetIntField (result, fid, (int) inp.vy);

	fid = env->GetFieldID(global_position_int_class, "vz", "I");
	env->SetIntField (result, fid, (int) inp.vz);

	fid = env->GetFieldID(global_position_int_class, "hdg", "I");
	env->SetIntField (result, fid, (int) inp.hdg);


	fid = env->GetFieldID(global_position_int_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(global_position_int_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_global_position_int(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(global_position_int_class, "time_boot_ms", "J"));
	int32_t lat = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_int_class, "lat", "J"));
	int32_t lon = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_int_class, "lon", "J"));
	int32_t alt = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_int_class, "alt", "J"));
	int32_t relative_alt = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_int_class, "relative_alt", "J"));
	int16_t vx = (int16_t)env->GetIntField (obj, env->GetFieldID(global_position_int_class, "vx", "I"));
	int16_t vy = (int16_t)env->GetIntField (obj, env->GetFieldID(global_position_int_class, "vy", "I"));
	int16_t vz = (int16_t)env->GetIntField (obj, env->GetFieldID(global_position_int_class, "vz", "I"));
	uint16_t hdg = (uint16_t)env->GetIntField (obj, env->GetFieldID(global_position_int_class, "hdg", "I"));


	mavlink_msg_global_position_int_pack(system_id, component_id, &msg,time_boot_ms, lat, lon, alt, relative_alt, vx, vy, vz, hdg);

}

jobject unpack_msg_rc_channels_scaled(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_rc_channels_scaled_t inp;
	mavlink_msg_rc_channels_scaled_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(rc_channels_scaled_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(rc_channels_scaled_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(rc_channels_scaled_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan1_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan1_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan2_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan2_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan3_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan3_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan4_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan4_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan5_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan5_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan6_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan6_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan7_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan7_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "chan8_scaled", "I");
	env->SetIntField (result, fid, (int) inp.chan8_scaled);

	fid = env->GetFieldID(rc_channels_scaled_class, "port", "I");
	env->SetIntField (result, fid, (int) inp.port);

	fid = env->GetFieldID(rc_channels_scaled_class, "rssi", "I");
	env->SetIntField (result, fid, (int) inp.rssi);


	fid = env->GetFieldID(rc_channels_scaled_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(rc_channels_scaled_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_rc_channels_scaled(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(rc_channels_scaled_class, "time_boot_ms", "J"));
	int16_t chan1_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan1_scaled", "I"));
	int16_t chan2_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan2_scaled", "I"));
	int16_t chan3_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan3_scaled", "I"));
	int16_t chan4_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan4_scaled", "I"));
	int16_t chan5_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan5_scaled", "I"));
	int16_t chan6_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan6_scaled", "I"));
	int16_t chan7_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan7_scaled", "I"));
	int16_t chan8_scaled = (int16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "chan8_scaled", "I"));
	uint8_t port = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "port", "I"));
	uint8_t rssi = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_scaled_class, "rssi", "I"));


	mavlink_msg_rc_channels_scaled_pack(system_id, component_id, &msg,time_boot_ms, port, chan1_scaled, chan2_scaled, chan3_scaled, chan4_scaled, chan5_scaled, chan6_scaled, chan7_scaled, chan8_scaled, rssi);

}

jobject unpack_msg_rc_channels_raw(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_rc_channels_raw_t inp;
	mavlink_msg_rc_channels_raw_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(rc_channels_raw_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(rc_channels_raw_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(rc_channels_raw_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(rc_channels_raw_class, "chan1_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan1_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan2_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan2_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan3_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan3_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan4_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan4_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan5_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan5_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan6_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan6_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan7_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan7_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "chan8_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan8_raw);

	fid = env->GetFieldID(rc_channels_raw_class, "port", "I");
	env->SetIntField (result, fid, (int) inp.port);

	fid = env->GetFieldID(rc_channels_raw_class, "rssi", "I");
	env->SetIntField (result, fid, (int) inp.rssi);


	fid = env->GetFieldID(rc_channels_raw_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(rc_channels_raw_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_rc_channels_raw(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(rc_channels_raw_class, "time_boot_ms", "J"));
	uint16_t chan1_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan1_raw", "I"));
	uint16_t chan2_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan2_raw", "I"));
	uint16_t chan3_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan3_raw", "I"));
	uint16_t chan4_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan4_raw", "I"));
	uint16_t chan5_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan5_raw", "I"));
	uint16_t chan6_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan6_raw", "I"));
	uint16_t chan7_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan7_raw", "I"));
	uint16_t chan8_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "chan8_raw", "I"));
	uint8_t port = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "port", "I"));
	uint8_t rssi = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_raw_class, "rssi", "I"));


	mavlink_msg_rc_channels_raw_pack(system_id, component_id, &msg,time_boot_ms, port, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw, rssi);

}

jobject unpack_msg_servo_output_raw(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_servo_output_raw_t inp;
	mavlink_msg_servo_output_raw_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(servo_output_raw_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(servo_output_raw_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(servo_output_raw_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(servo_output_raw_class, "servo1_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo1_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo2_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo2_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo3_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo3_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo4_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo4_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo5_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo5_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo6_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo6_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo7_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo7_raw);

	fid = env->GetFieldID(servo_output_raw_class, "servo8_raw", "I");
	env->SetIntField (result, fid, (int) inp.servo8_raw);

	fid = env->GetFieldID(servo_output_raw_class, "port", "I");
	env->SetIntField (result, fid, (int) inp.port);


	fid = env->GetFieldID(servo_output_raw_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(servo_output_raw_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_servo_output_raw(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_usec = (uint32_t)env->GetLongField (obj, env->GetFieldID(servo_output_raw_class, "time_usec", "J"));
	uint16_t servo1_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo1_raw", "I"));
	uint16_t servo2_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo2_raw", "I"));
	uint16_t servo3_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo3_raw", "I"));
	uint16_t servo4_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo4_raw", "I"));
	uint16_t servo5_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo5_raw", "I"));
	uint16_t servo6_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo6_raw", "I"));
	uint16_t servo7_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo7_raw", "I"));
	uint16_t servo8_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "servo8_raw", "I"));
	uint8_t port = (uint8_t)env->GetIntField (obj, env->GetFieldID(servo_output_raw_class, "port", "I"));


	mavlink_msg_servo_output_raw_pack(system_id, component_id, &msg,time_usec, port, servo1_raw, servo2_raw, servo3_raw, servo4_raw, servo5_raw, servo6_raw, servo7_raw, servo8_raw);

}

jobject unpack_msg_mission_request_partial_list(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_request_partial_list_t inp;
	mavlink_msg_mission_request_partial_list_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_request_partial_list_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_request_partial_list_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_request_partial_list_class, "start_index", "I");
	env->SetIntField (result, fid, (int) inp.start_index);

	fid = env->GetFieldID(mission_request_partial_list_class, "end_index", "I");
	env->SetIntField (result, fid, (int) inp.end_index);

	fid = env->GetFieldID(mission_request_partial_list_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_request_partial_list_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_request_partial_list_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_request_partial_list_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_request_partial_list(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int16_t start_index = (int16_t)env->GetIntField (obj, env->GetFieldID(mission_request_partial_list_class, "start_index", "I"));
	int16_t end_index = (int16_t)env->GetIntField (obj, env->GetFieldID(mission_request_partial_list_class, "end_index", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_request_partial_list_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_request_partial_list_class, "target_component", "I"));


	mavlink_msg_mission_request_partial_list_pack(system_id, component_id, &msg,target_system, target_component, start_index, end_index);

}

jobject unpack_msg_mission_write_partial_list(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_write_partial_list_t inp;
	mavlink_msg_mission_write_partial_list_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_write_partial_list_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_write_partial_list_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_write_partial_list_class, "start_index", "I");
	env->SetIntField (result, fid, (int) inp.start_index);

	fid = env->GetFieldID(mission_write_partial_list_class, "end_index", "I");
	env->SetIntField (result, fid, (int) inp.end_index);

	fid = env->GetFieldID(mission_write_partial_list_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_write_partial_list_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_write_partial_list_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_write_partial_list_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_write_partial_list(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int16_t start_index = (int16_t)env->GetIntField (obj, env->GetFieldID(mission_write_partial_list_class, "start_index", "I"));
	int16_t end_index = (int16_t)env->GetIntField (obj, env->GetFieldID(mission_write_partial_list_class, "end_index", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_write_partial_list_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_write_partial_list_class, "target_component", "I"));


	mavlink_msg_mission_write_partial_list_pack(system_id, component_id, &msg,target_system, target_component, start_index, end_index);

}

jobject unpack_msg_mission_item(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_item_t inp;
	mavlink_msg_mission_item_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_item_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_item_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_item_class, "param1", "F");
	env->SetFloatField (result, fid, (float)inp.param1);

	fid = env->GetFieldID(mission_item_class, "param2", "F");
	env->SetFloatField (result, fid, (float)inp.param2);

	fid = env->GetFieldID(mission_item_class, "param3", "F");
	env->SetFloatField (result, fid, (float)inp.param3);

	fid = env->GetFieldID(mission_item_class, "param4", "F");
	env->SetFloatField (result, fid, (float)inp.param4);

	fid = env->GetFieldID(mission_item_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(mission_item_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(mission_item_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(mission_item_class, "seq", "I");
	env->SetIntField (result, fid, (int) inp.seq);

	fid = env->GetFieldID(mission_item_class, "command", "I");
	env->SetIntField (result, fid, (int) inp.command);

	fid = env->GetFieldID(mission_item_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_item_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(mission_item_class, "frame", "I");
	env->SetIntField (result, fid, (int) inp.frame);

	fid = env->GetFieldID(mission_item_class, "current", "I");
	env->SetIntField (result, fid, (int) inp.current);

	fid = env->GetFieldID(mission_item_class, "autocontinue", "I");
	env->SetIntField (result, fid, (int) inp.autocontinue);


	fid = env->GetFieldID(mission_item_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_item_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_item(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float param1 = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "param1", "F"));
	float param2 = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "param2", "F"));
	float param3 = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "param3", "F"));
	float param4 = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "param4", "F"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(mission_item_class, "z", "F"));
	uint16_t seq = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "seq", "I"));
	uint16_t command = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "command", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "target_component", "I"));
	uint8_t frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "frame", "I"));
	uint8_t current = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "current", "I"));
	uint8_t autocontinue = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_item_class, "autocontinue", "I"));


	mavlink_msg_mission_item_pack(system_id, component_id, &msg,target_system, target_component, seq, frame, command, current, autocontinue, param1, param2, param3, param4, x, y, z);

}

jobject unpack_msg_mission_request(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_request_t inp;
	mavlink_msg_mission_request_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_request_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_request_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_request_class, "seq", "I");
	env->SetIntField (result, fid, (int) inp.seq);

	fid = env->GetFieldID(mission_request_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_request_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_request_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_request_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_request(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t seq = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_request_class, "seq", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_request_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_request_class, "target_component", "I"));


	mavlink_msg_mission_request_pack(system_id, component_id, &msg,target_system, target_component, seq);

}

jobject unpack_msg_mission_set_current(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_set_current_t inp;
	mavlink_msg_mission_set_current_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_set_current_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_set_current_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_set_current_class, "seq", "I");
	env->SetIntField (result, fid, (int) inp.seq);

	fid = env->GetFieldID(mission_set_current_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_set_current_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_set_current_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_set_current_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_set_current(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t seq = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_set_current_class, "seq", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_set_current_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_set_current_class, "target_component", "I"));


	mavlink_msg_mission_set_current_pack(system_id, component_id, &msg,target_system, target_component, seq);

}

jobject unpack_msg_mission_current(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_current_t inp;
	mavlink_msg_mission_current_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_current_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_current_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_current_class, "seq", "I");
	env->SetIntField (result, fid, (int) inp.seq);


	fid = env->GetFieldID(mission_current_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_current_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_current(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t seq = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_current_class, "seq", "I"));


	mavlink_msg_mission_current_pack(system_id, component_id, &msg,seq);

}

jobject unpack_msg_mission_request_list(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_request_list_t inp;
	mavlink_msg_mission_request_list_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_request_list_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_request_list_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_request_list_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_request_list_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_request_list_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_request_list_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_request_list(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int target_system =   env->GetIntField (obj, env->GetFieldID(mission_request_list_class, "target_system", "I"));
	int target_component =env->GetIntField (obj, env->GetFieldID(mission_request_list_class, "target_component", "I"));
	mavlink_msg_mission_request_list_pack(system_id, component_id, &msg,target_system, target_component);
}

jobject unpack_msg_mission_count(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_count_t inp;
	mavlink_msg_mission_count_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_count_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_count_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_count_class, "count", "I");
	env->SetIntField (result, fid, (int) inp.count);

	fid = env->GetFieldID(mission_count_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_count_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_count_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_count_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_count(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t count = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_count_class, "count", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_count_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_count_class, "target_component", "I"));


	mavlink_msg_mission_count_pack(system_id, component_id, &msg,target_system, target_component, count);

}

jobject unpack_msg_mission_clear_all(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_clear_all_t inp;
	mavlink_msg_mission_clear_all_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_clear_all_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_clear_all_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_clear_all_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_clear_all_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mission_clear_all_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_clear_all_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_clear_all(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_clear_all_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_clear_all_class, "target_component", "I"));


	mavlink_msg_mission_clear_all_pack(system_id, component_id, &msg,target_system, target_component);

}

jobject unpack_msg_mission_item_reached(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_item_reached_t inp;
	mavlink_msg_mission_item_reached_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_item_reached_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_item_reached_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_item_reached_class, "seq", "I");
	env->SetIntField (result, fid, (int) inp.seq);


	fid = env->GetFieldID(mission_item_reached_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_item_reached_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_item_reached(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t seq = (uint16_t)env->GetIntField (obj, env->GetFieldID(mission_item_reached_class, "seq", "I"));


	mavlink_msg_mission_item_reached_pack(system_id, component_id, &msg,seq);

}

jobject unpack_msg_mission_ack(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mission_ack_t inp;
	mavlink_msg_mission_ack_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mission_ack_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mission_ack_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mission_ack_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mission_ack_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(mission_ack_class, "type", "I");
	env->SetIntField (result, fid, (int) inp.type);


	fid = env->GetFieldID(mission_ack_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mission_ack_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mission_ack(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_ack_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_ack_class, "target_component", "I"));
	uint8_t type = (uint8_t)env->GetIntField (obj, env->GetFieldID(mission_ack_class, "type", "I"));


	mavlink_msg_mission_ack_pack(system_id, component_id, &msg,target_system, target_component, type);

}

jobject unpack_msg_set_gps_global_origin(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_gps_global_origin_t inp;
	mavlink_msg_set_gps_global_origin_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_gps_global_origin_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_gps_global_origin_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_gps_global_origin_class, "latitude", "J");
	env->SetLongField (result, fid, (long) inp.latitude);

	fid = env->GetFieldID(set_gps_global_origin_class, "longitude", "J");
	env->SetLongField (result, fid, (long) inp.longitude);

	fid = env->GetFieldID(set_gps_global_origin_class, "altitude", "J");
	env->SetLongField (result, fid, (long) inp.altitude);

	fid = env->GetFieldID(set_gps_global_origin_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);


	fid = env->GetFieldID(set_gps_global_origin_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_gps_global_origin_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_gps_global_origin(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t latitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_gps_global_origin_class, "latitude", "J"));
	int32_t longitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_gps_global_origin_class, "longitude", "J"));
	int32_t altitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_gps_global_origin_class, "altitude", "J"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_gps_global_origin_class, "target_system", "I"));


	mavlink_msg_set_gps_global_origin_pack(system_id, component_id, &msg,target_system, latitude, longitude, altitude);

}

jobject unpack_msg_gps_global_origin(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_gps_global_origin_t inp;
	mavlink_msg_gps_global_origin_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(gps_global_origin_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(gps_global_origin_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(gps_global_origin_class, "latitude", "J");
	env->SetLongField (result, fid, (long) inp.latitude);

	fid = env->GetFieldID(gps_global_origin_class, "longitude", "J");
	env->SetLongField (result, fid, (long) inp.longitude);

	fid = env->GetFieldID(gps_global_origin_class, "altitude", "J");
	env->SetLongField (result, fid, (long) inp.altitude);


	fid = env->GetFieldID(gps_global_origin_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(gps_global_origin_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_gps_global_origin(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t latitude = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_global_origin_class, "latitude", "J"));
	int32_t longitude = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_global_origin_class, "longitude", "J"));
	int32_t altitude = (int32_t)env->GetLongField (obj, env->GetFieldID(gps_global_origin_class, "altitude", "J"));


	mavlink_msg_gps_global_origin_pack(system_id, component_id, &msg,latitude, longitude, altitude);

}

jobject unpack_msg_set_local_position_setpoint(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_local_position_setpoint_t inp;
	mavlink_msg_set_local_position_setpoint_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_local_position_setpoint_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_local_position_setpoint_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_local_position_setpoint_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(set_local_position_setpoint_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(set_local_position_setpoint_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(set_local_position_setpoint_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(set_local_position_setpoint_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(set_local_position_setpoint_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(set_local_position_setpoint_class, "coordinate_frame", "I");
	env->SetIntField (result, fid, (int) inp.coordinate_frame);


	fid = env->GetFieldID(set_local_position_setpoint_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_local_position_setpoint_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_local_position_setpoint(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float x = (float)env->GetFloatField (obj, env->GetFieldID(set_local_position_setpoint_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(set_local_position_setpoint_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(set_local_position_setpoint_class, "z", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(set_local_position_setpoint_class, "yaw", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_local_position_setpoint_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_local_position_setpoint_class, "target_component", "I"));
	uint8_t coordinate_frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_local_position_setpoint_class, "coordinate_frame", "I"));


	mavlink_msg_set_local_position_setpoint_pack(system_id, component_id, &msg,target_system, target_component, coordinate_frame, x, y, z, yaw);

}

jobject unpack_msg_local_position_setpoint(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_local_position_setpoint_t inp;
	mavlink_msg_local_position_setpoint_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(local_position_setpoint_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(local_position_setpoint_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(local_position_setpoint_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(local_position_setpoint_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(local_position_setpoint_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(local_position_setpoint_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(local_position_setpoint_class, "coordinate_frame", "I");
	env->SetIntField (result, fid, (int) inp.coordinate_frame);


	fid = env->GetFieldID(local_position_setpoint_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(local_position_setpoint_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_local_position_setpoint(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float x = (float)env->GetFloatField (obj, env->GetFieldID(local_position_setpoint_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(local_position_setpoint_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(local_position_setpoint_class, "z", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(local_position_setpoint_class, "yaw", "F"));
	uint8_t coordinate_frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(local_position_setpoint_class, "coordinate_frame", "I"));


	mavlink_msg_local_position_setpoint_pack(system_id, component_id, &msg,coordinate_frame, x, y, z, yaw);

}

jobject unpack_msg_global_position_setpoint_int(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_global_position_setpoint_int_t inp;
	mavlink_msg_global_position_setpoint_int_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(global_position_setpoint_int_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(global_position_setpoint_int_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(global_position_setpoint_int_class, "latitude", "J");
	env->SetLongField (result, fid, (long) inp.latitude);

	fid = env->GetFieldID(global_position_setpoint_int_class, "longitude", "J");
	env->SetLongField (result, fid, (long) inp.longitude);

	fid = env->GetFieldID(global_position_setpoint_int_class, "altitude", "J");
	env->SetLongField (result, fid, (long) inp.altitude);

	fid = env->GetFieldID(global_position_setpoint_int_class, "yaw", "I");
	env->SetIntField (result, fid, (int) inp.yaw);

	fid = env->GetFieldID(global_position_setpoint_int_class, "coordinate_frame", "I");
	env->SetIntField (result, fid, (int) inp.coordinate_frame);


	fid = env->GetFieldID(global_position_setpoint_int_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(global_position_setpoint_int_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_global_position_setpoint_int(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t latitude = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_setpoint_int_class, "latitude", "J"));
	int32_t longitude = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_setpoint_int_class, "longitude", "J"));
	int32_t altitude = (int32_t)env->GetLongField (obj, env->GetFieldID(global_position_setpoint_int_class, "altitude", "J"));
	int16_t yaw = (int16_t)env->GetIntField (obj, env->GetFieldID(global_position_setpoint_int_class, "yaw", "I"));
	uint8_t coordinate_frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(global_position_setpoint_int_class, "coordinate_frame", "I"));


	mavlink_msg_global_position_setpoint_int_pack(system_id, component_id, &msg,coordinate_frame, latitude, longitude, altitude, yaw);

}

jobject unpack_msg_set_global_position_setpoint_int(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_global_position_setpoint_int_t inp;
	mavlink_msg_set_global_position_setpoint_int_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_global_position_setpoint_int_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_global_position_setpoint_int_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_global_position_setpoint_int_class, "latitude", "J");
	env->SetLongField (result, fid, (long) inp.latitude);

	fid = env->GetFieldID(set_global_position_setpoint_int_class, "longitude", "J");
	env->SetLongField (result, fid, (long) inp.longitude);

	fid = env->GetFieldID(set_global_position_setpoint_int_class, "altitude", "J");
	env->SetLongField (result, fid, (long) inp.altitude);

	fid = env->GetFieldID(set_global_position_setpoint_int_class, "yaw", "I");
	env->SetIntField (result, fid, (int) inp.yaw);

	fid = env->GetFieldID(set_global_position_setpoint_int_class, "coordinate_frame", "I");
	env->SetIntField (result, fid, (int) inp.coordinate_frame);


	fid = env->GetFieldID(set_global_position_setpoint_int_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_global_position_setpoint_int_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_global_position_setpoint_int(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t latitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_global_position_setpoint_int_class, "latitude", "J"));
	int32_t longitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_global_position_setpoint_int_class, "longitude", "J"));
	int32_t altitude = (int32_t)env->GetLongField (obj, env->GetFieldID(set_global_position_setpoint_int_class, "altitude", "J"));
	int16_t yaw = (int16_t)env->GetIntField (obj, env->GetFieldID(set_global_position_setpoint_int_class, "yaw", "I"));
	uint8_t coordinate_frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_global_position_setpoint_int_class, "coordinate_frame", "I"));


	mavlink_msg_set_global_position_setpoint_int_pack(system_id, component_id, &msg,coordinate_frame, latitude, longitude, altitude, yaw);

}

jobject unpack_msg_safety_set_allowed_area(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_safety_set_allowed_area_t inp;
	mavlink_msg_safety_set_allowed_area_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(safety_set_allowed_area_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(safety_set_allowed_area_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(safety_set_allowed_area_class, "p1x", "F");
	env->SetFloatField (result, fid, (float)inp.p1x);

	fid = env->GetFieldID(safety_set_allowed_area_class, "p1y", "F");
	env->SetFloatField (result, fid, (float)inp.p1y);

	fid = env->GetFieldID(safety_set_allowed_area_class, "p1z", "F");
	env->SetFloatField (result, fid, (float)inp.p1z);

	fid = env->GetFieldID(safety_set_allowed_area_class, "p2x", "F");
	env->SetFloatField (result, fid, (float)inp.p2x);

	fid = env->GetFieldID(safety_set_allowed_area_class, "p2y", "F");
	env->SetFloatField (result, fid, (float)inp.p2y);

	fid = env->GetFieldID(safety_set_allowed_area_class, "p2z", "F");
	env->SetFloatField (result, fid, (float)inp.p2z);

	fid = env->GetFieldID(safety_set_allowed_area_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(safety_set_allowed_area_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(safety_set_allowed_area_class, "frame", "I");
	env->SetIntField (result, fid, (int) inp.frame);


	fid = env->GetFieldID(safety_set_allowed_area_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(safety_set_allowed_area_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_safety_set_allowed_area(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float p1x = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p1x", "F"));
	float p1y = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p1y", "F"));
	float p1z = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p1z", "F"));
	float p2x = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p2x", "F"));
	float p2y = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p2y", "F"));
	float p2z = (float)env->GetFloatField (obj, env->GetFieldID(safety_set_allowed_area_class, "p2z", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(safety_set_allowed_area_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(safety_set_allowed_area_class, "target_component", "I"));
	uint8_t frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(safety_set_allowed_area_class, "frame", "I"));


	mavlink_msg_safety_set_allowed_area_pack(system_id, component_id, &msg,target_system, target_component, frame, p1x, p1y, p1z, p2x, p2y, p2z);

}

jobject unpack_msg_safety_allowed_area(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_safety_allowed_area_t inp;
	mavlink_msg_safety_allowed_area_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(safety_allowed_area_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(safety_allowed_area_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(safety_allowed_area_class, "p1x", "F");
	env->SetFloatField (result, fid, (float)inp.p1x);

	fid = env->GetFieldID(safety_allowed_area_class, "p1y", "F");
	env->SetFloatField (result, fid, (float)inp.p1y);

	fid = env->GetFieldID(safety_allowed_area_class, "p1z", "F");
	env->SetFloatField (result, fid, (float)inp.p1z);

	fid = env->GetFieldID(safety_allowed_area_class, "p2x", "F");
	env->SetFloatField (result, fid, (float)inp.p2x);

	fid = env->GetFieldID(safety_allowed_area_class, "p2y", "F");
	env->SetFloatField (result, fid, (float)inp.p2y);

	fid = env->GetFieldID(safety_allowed_area_class, "p2z", "F");
	env->SetFloatField (result, fid, (float)inp.p2z);

	fid = env->GetFieldID(safety_allowed_area_class, "frame", "I");
	env->SetIntField (result, fid, (int) inp.frame);


	fid = env->GetFieldID(safety_allowed_area_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(safety_allowed_area_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_safety_allowed_area(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float p1x = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p1x", "F"));
	float p1y = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p1y", "F"));
	float p1z = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p1z", "F"));
	float p2x = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p2x", "F"));
	float p2y = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p2y", "F"));
	float p2z = (float)env->GetFloatField (obj, env->GetFieldID(safety_allowed_area_class, "p2z", "F"));
	uint8_t frame = (uint8_t)env->GetIntField (obj, env->GetFieldID(safety_allowed_area_class, "frame", "I"));


	mavlink_msg_safety_allowed_area_pack(system_id, component_id, &msg,frame, p1x, p1y, p1z, p2x, p2y, p2z);

}

jobject unpack_msg_set_roll_pitch_yaw_thrust(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_roll_pitch_yaw_thrust_t inp;
	mavlink_msg_set_roll_pitch_yaw_thrust_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_roll_pitch_yaw_thrust_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_roll_pitch_yaw_thrust_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "thrust", "F");
	env->SetFloatField (result, fid, (float)inp.thrust);

	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_roll_pitch_yaw_thrust_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_roll_pitch_yaw_thrust(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "yaw", "F"));
	float thrust = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "thrust", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_roll_pitch_yaw_thrust_class, "target_component", "I"));


	mavlink_msg_set_roll_pitch_yaw_thrust_pack(system_id, component_id, &msg,target_system, target_component, roll, pitch, yaw, thrust);

}

jobject unpack_msg_set_roll_pitch_yaw_speed_thrust(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_roll_pitch_yaw_speed_thrust_t inp;
	mavlink_msg_set_roll_pitch_yaw_speed_thrust_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_roll_pitch_yaw_speed_thrust_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_roll_pitch_yaw_speed_thrust_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "roll_speed", "F");
	env->SetFloatField (result, fid, (float)inp.roll_speed);

	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "pitch_speed", "F");
	env->SetFloatField (result, fid, (float)inp.pitch_speed);

	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "yaw_speed", "F");
	env->SetFloatField (result, fid, (float)inp.yaw_speed);

	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "thrust", "F");
	env->SetFloatField (result, fid, (float)inp.thrust);

	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_roll_pitch_yaw_speed_thrust(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float roll_speed = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "roll_speed", "F"));
	float pitch_speed = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "pitch_speed", "F"));
	float yaw_speed = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "yaw_speed", "F"));
	float thrust = (float)env->GetFloatField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "thrust", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_roll_pitch_yaw_speed_thrust_class, "target_component", "I"));


	mavlink_msg_set_roll_pitch_yaw_speed_thrust_pack(system_id, component_id, &msg,target_system, target_component, roll_speed, pitch_speed, yaw_speed, thrust);

}

jobject unpack_msg_roll_pitch_yaw_thrust_setpoint(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_roll_pitch_yaw_thrust_setpoint_t inp;
	mavlink_msg_roll_pitch_yaw_thrust_setpoint_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(roll_pitch_yaw_thrust_setpoint_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(roll_pitch_yaw_thrust_setpoint_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "thrust", "F");
	env->SetFloatField (result, fid, (float)inp.thrust);


	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_roll_pitch_yaw_thrust_setpoint(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "time_boot_ms", "J"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "yaw", "F"));
	float thrust = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_thrust_setpoint_class, "thrust", "F"));


	mavlink_msg_roll_pitch_yaw_thrust_setpoint_pack(system_id, component_id, &msg,time_boot_ms, roll, pitch, yaw, thrust);

}

jobject unpack_msg_roll_pitch_yaw_speed_thrust_setpoint(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_roll_pitch_yaw_speed_thrust_setpoint_t inp;
	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(roll_pitch_yaw_speed_thrust_setpoint_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(roll_pitch_yaw_speed_thrust_setpoint_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "roll_speed", "F");
	env->SetFloatField (result, fid, (float)inp.roll_speed);

	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "pitch_speed", "F");
	env->SetFloatField (result, fid, (float)inp.pitch_speed);

	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "yaw_speed", "F");
	env->SetFloatField (result, fid, (float)inp.yaw_speed);

	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "thrust", "F");
	env->SetFloatField (result, fid, (float)inp.thrust);


	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_roll_pitch_yaw_speed_thrust_setpoint(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "time_boot_ms", "J"));
	float roll_speed = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "roll_speed", "F"));
	float pitch_speed = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "pitch_speed", "F"));
	float yaw_speed = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "yaw_speed", "F"));
	float thrust = (float)env->GetFloatField (obj, env->GetFieldID(roll_pitch_yaw_speed_thrust_setpoint_class, "thrust", "F"));


	mavlink_msg_roll_pitch_yaw_speed_thrust_setpoint_pack(system_id, component_id, &msg,time_boot_ms, roll_speed, pitch_speed, yaw_speed, thrust);

}

jobject unpack_msg_nav_controller_output(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_nav_controller_output_t inp;
	mavlink_msg_nav_controller_output_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(nav_controller_output_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(nav_controller_output_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(nav_controller_output_class, "nav_roll", "F");
	env->SetFloatField (result, fid, (float)inp.nav_roll);

	fid = env->GetFieldID(nav_controller_output_class, "nav_pitch", "F");
	env->SetFloatField (result, fid, (float)inp.nav_pitch);

	fid = env->GetFieldID(nav_controller_output_class, "alt_error", "F");
	env->SetFloatField (result, fid, (float)inp.alt_error);

	fid = env->GetFieldID(nav_controller_output_class, "aspd_error", "F");
	env->SetFloatField (result, fid, (float)inp.aspd_error);

	fid = env->GetFieldID(nav_controller_output_class, "xtrack_error", "F");
	env->SetFloatField (result, fid, (float)inp.xtrack_error);

	fid = env->GetFieldID(nav_controller_output_class, "nav_bearing", "I");
	env->SetIntField (result, fid, (int) inp.nav_bearing);

	fid = env->GetFieldID(nav_controller_output_class, "target_bearing", "I");
	env->SetIntField (result, fid, (int) inp.target_bearing);

	fid = env->GetFieldID(nav_controller_output_class, "wp_dist", "I");
	env->SetIntField (result, fid, (int) inp.wp_dist);


	fid = env->GetFieldID(nav_controller_output_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(nav_controller_output_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_nav_controller_output(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float nav_roll = (float)env->GetFloatField (obj, env->GetFieldID(nav_controller_output_class, "nav_roll", "F"));
	float nav_pitch = (float)env->GetFloatField (obj, env->GetFieldID(nav_controller_output_class, "nav_pitch", "F"));
	float alt_error = (float)env->GetFloatField (obj, env->GetFieldID(nav_controller_output_class, "alt_error", "F"));
	float aspd_error = (float)env->GetFloatField (obj, env->GetFieldID(nav_controller_output_class, "aspd_error", "F"));
	float xtrack_error = (float)env->GetFloatField (obj, env->GetFieldID(nav_controller_output_class, "xtrack_error", "F"));
	int16_t nav_bearing = (int16_t)env->GetIntField (obj, env->GetFieldID(nav_controller_output_class, "nav_bearing", "I"));
	int16_t target_bearing = (int16_t)env->GetIntField (obj, env->GetFieldID(nav_controller_output_class, "target_bearing", "I"));
	uint16_t wp_dist = (uint16_t)env->GetIntField (obj, env->GetFieldID(nav_controller_output_class, "wp_dist", "I"));


	mavlink_msg_nav_controller_output_pack(system_id, component_id, &msg,nav_roll, nav_pitch, nav_bearing, target_bearing, wp_dist, alt_error, aspd_error, xtrack_error);

}

jobject unpack_msg_state_correction(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_state_correction_t inp;
	mavlink_msg_state_correction_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(state_correction_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(state_correction_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(state_correction_class, "xErr", "F");
	env->SetFloatField (result, fid, (float)inp.xErr);

	fid = env->GetFieldID(state_correction_class, "yErr", "F");
	env->SetFloatField (result, fid, (float)inp.yErr);

	fid = env->GetFieldID(state_correction_class, "zErr", "F");
	env->SetFloatField (result, fid, (float)inp.zErr);

	fid = env->GetFieldID(state_correction_class, "rollErr", "F");
	env->SetFloatField (result, fid, (float)inp.rollErr);

	fid = env->GetFieldID(state_correction_class, "pitchErr", "F");
	env->SetFloatField (result, fid, (float)inp.pitchErr);

	fid = env->GetFieldID(state_correction_class, "yawErr", "F");
	env->SetFloatField (result, fid, (float)inp.yawErr);

	fid = env->GetFieldID(state_correction_class, "vxErr", "F");
	env->SetFloatField (result, fid, (float)inp.vxErr);

	fid = env->GetFieldID(state_correction_class, "vyErr", "F");
	env->SetFloatField (result, fid, (float)inp.vyErr);

	fid = env->GetFieldID(state_correction_class, "vzErr", "F");
	env->SetFloatField (result, fid, (float)inp.vzErr);


	fid = env->GetFieldID(state_correction_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(state_correction_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_state_correction(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float xErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "xErr", "F"));
	float yErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "yErr", "F"));
	float zErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "zErr", "F"));
	float rollErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "rollErr", "F"));
	float pitchErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "pitchErr", "F"));
	float yawErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "yawErr", "F"));
	float vxErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "vxErr", "F"));
	float vyErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "vyErr", "F"));
	float vzErr = (float)env->GetFloatField (obj, env->GetFieldID(state_correction_class, "vzErr", "F"));


	mavlink_msg_state_correction_pack(system_id, component_id, &msg,xErr, yErr, zErr, rollErr, pitchErr, yawErr, vxErr, vyErr, vzErr);

}

jobject unpack_msg_request_data_stream(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_request_data_stream_t inp;
	mavlink_msg_request_data_stream_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(request_data_stream_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(request_data_stream_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(request_data_stream_class, "req_message_rate", "I");
	env->SetIntField (result, fid, (int) inp.req_message_rate);

	fid = env->GetFieldID(request_data_stream_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(request_data_stream_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(request_data_stream_class, "req_stream_id", "I");
	env->SetIntField (result, fid, (int) inp.req_stream_id);

	fid = env->GetFieldID(request_data_stream_class, "start_stop", "I");
	env->SetIntField (result, fid, (int) inp.start_stop);


	fid = env->GetFieldID(request_data_stream_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(request_data_stream_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_request_data_stream(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t req_message_rate = (uint16_t)env->GetIntField (obj, env->GetFieldID(request_data_stream_class, "req_message_rate", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(request_data_stream_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(request_data_stream_class, "target_component", "I"));
	uint8_t req_stream_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(request_data_stream_class, "req_stream_id", "I"));
	uint8_t start_stop = (uint8_t)env->GetIntField (obj, env->GetFieldID(request_data_stream_class, "start_stop", "I"));


	mavlink_msg_request_data_stream_pack(system_id, component_id, &msg,target_system, target_component, req_stream_id, req_message_rate, start_stop);

}

jobject unpack_msg_data_stream(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_data_stream_t inp;
	mavlink_msg_data_stream_decode(&message, &inp);
	jmethodID cid = env->GetMethodID(data_stream_class, "<init>", "()V");
	if (cid == NULL) return NULL;	jobject result = env->NewObject(data_stream_class, cid);

	/* TODO
	// Create the object

	//Set values
	jfieldID fid;
	fid = env->GetFieldID(data_stream_class, "message_rate", "I");
	env->SetIntField (result, fid, (int) inp.message_rate);

	fid = env->GetFieldID(data_stream_class, "stream_id"clea, "I");
	env->SetIntField (result, fid, (int) inp.stream_id);

	fid = env->GetFieldID(data_stream_class, "on_off", "I");
	env->SetIntField (result, fid, (int) inp.on_off);


	fid = env->GetFieldID(data_stream_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(data_stream_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_data_stream(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t message_rate = (uint16_t)env->GetIntField (obj, env->GetFieldID(data_stream_class, "message_rate", "I"));
	uint8_t stream_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(data_stream_class, "stream_id", "I"));
	uint8_t on_off = (uint8_t)env->GetIntField (obj, env->GetFieldID(data_stream_class, "on_off", "I"));


	mavlink_msg_data_stream_pack(system_id, component_id, &msg,stream_id, message_rate, on_off);

}

jobject unpack_msg_manual_control(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_manual_control_t inp;
	mavlink_msg_manual_control_decode(&message, &inp);
	jmethodID cid = env->GetMethodID(manual_control_class, "<init>", "()V");
		if (cid == NULL) return NULL;

		jobject result = env->NewObject(manual_control_class, cid);
	/*TODO
	// Create the object

	//Set values
	jfieldID fid;
	fid = env->GetFieldID(manual_control_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(manual_control_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(manual_control_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(manual_control_class, "thrust", "F");
	env->SetFloatField (result, fid, (float)inp.thrust);

	fid = env->GetFieldID(manual_control_class, "target", "I");
	env->SetIntField (result, fid, (int) inp.target);

	fid = env->GetFieldID(manual_control_class, "roll_manual", "I");
	env->SetIntField (result, fid, (int) inp.roll_manual);

	fid = env->GetFieldID(manual_control_class, "pitch_manual", "I");
	env->SetIntField (result, fid, (int) inp.pitch_manual);

	fid = env->GetFieldID(manual_control_class, "yaw_manual", "I");
	env->SetIntField (result, fid, (int) inp.yaw_manual);

	fid = env->GetFieldID(manual_control_class, "thrust_manual", "I");
	env->SetIntField (result, fid, (int) inp.thrust_manual);


	fid = env->GetFieldID(manual_control_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(manual_control_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_manual_control(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	/*
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(manual_control_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(manual_control_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(manual_control_class, "yaw", "F"));
	float thrust = (float)env->GetFloatField (obj, env->GetFieldID(manual_control_class, "thrust", "F"));
	uint8_t target = (uint8_t)env->GetIntField (obj, env->GetFieldID(manual_control_class, "target", "I"));
	uint8_t roll_manual = (uint8_t)env->GetIntField (obj, env->GetFieldID(manual_control_class, "roll_manual", "I"));
	uint8_t pitch_manual = (uint8_t)env->GetIntField (obj, env->GetFieldID(manual_control_class, "pitch_manual", "I"));
	uint8_t yaw_manual = (uint8_t)env->GetIntField (obj, env->GetFieldID(manual_control_class, "yaw_manual", "I"));
	uint8_t thrust_manual = (uint8_t)env->GetIntField (obj, env->GetFieldID(manual_control_class, "thrust_manual", "I"));


	mavlink_msg_manual_control_pack(system_id, component_id, &msg,target, roll, pitch, yaw, thrust, roll_manual, pitch_manual, yaw_manual, thrust_manual);
	*/

}

jobject unpack_msg_rc_channels_override(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_rc_channels_override_t inp;
	mavlink_msg_rc_channels_override_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(rc_channels_override_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(rc_channels_override_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(rc_channels_override_class, "chan1_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan1_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan2_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan2_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan3_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan3_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan4_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan4_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan5_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan5_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan6_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan6_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan7_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan7_raw);

	fid = env->GetFieldID(rc_channels_override_class, "chan8_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan8_raw);

	fid = env->GetFieldID(rc_channels_override_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(rc_channels_override_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(rc_channels_override_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(rc_channels_override_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_rc_channels_override(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t chan1_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan1_raw", "I"));
	uint16_t chan2_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan2_raw", "I"));
	uint16_t chan3_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan3_raw", "I"));
	uint16_t chan4_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan4_raw", "I"));
	uint16_t chan5_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan5_raw", "I"));
	uint16_t chan6_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan6_raw", "I"));
	uint16_t chan7_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan7_raw", "I"));
	uint16_t chan8_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "chan8_raw", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(rc_channels_override_class, "target_component", "I"));


	mavlink_msg_rc_channels_override_pack(system_id, component_id, &msg,target_system, target_component, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw);

}

jobject unpack_msg_vfr_hud(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_vfr_hud_t inp;
	mavlink_msg_vfr_hud_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(vfr_hud_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(vfr_hud_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(vfr_hud_class, "airspeed", "F");
	env->SetFloatField (result, fid, (float)inp.airspeed);

	fid = env->GetFieldID(vfr_hud_class, "groundspeed", "F");
	env->SetFloatField (result, fid, (float)inp.groundspeed);

	fid = env->GetFieldID(vfr_hud_class, "alt", "F");
	env->SetFloatField (result, fid, (float)inp.alt);

	fid = env->GetFieldID(vfr_hud_class, "climb", "F");
	env->SetFloatField (result, fid, (float)inp.climb);

	fid = env->GetFieldID(vfr_hud_class, "heading", "I");
	env->SetIntField (result, fid, (int) inp.heading);

	fid = env->GetFieldID(vfr_hud_class, "throttle", "I");
	env->SetIntField (result, fid, (int) inp.throttle);


	fid = env->GetFieldID(vfr_hud_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(vfr_hud_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_vfr_hud(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float airspeed = (float)env->GetFloatField (obj, env->GetFieldID(vfr_hud_class, "airspeed", "F"));
	float groundspeed = (float)env->GetFloatField (obj, env->GetFieldID(vfr_hud_class, "groundspeed", "F"));
	float alt = (float)env->GetFloatField (obj, env->GetFieldID(vfr_hud_class, "alt", "F"));
	float climb = (float)env->GetFloatField (obj, env->GetFieldID(vfr_hud_class, "climb", "F"));
	int16_t heading = (int16_t)env->GetIntField (obj, env->GetFieldID(vfr_hud_class, "heading", "I"));
	uint16_t throttle = (uint16_t)env->GetIntField (obj, env->GetFieldID(vfr_hud_class, "throttle", "I"));


	mavlink_msg_vfr_hud_pack(system_id, component_id, &msg,airspeed, groundspeed, heading, throttle, alt, climb);

}

jobject unpack_msg_command_long(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_command_long_t inp;
	mavlink_msg_command_long_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(command_long_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(command_long_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(command_long_class, "param1", "F");
	env->SetFloatField (result, fid, (float)inp.param1);

	fid = env->GetFieldID(command_long_class, "param2", "F");
	env->SetFloatField (result, fid, (float)inp.param2);

	fid = env->GetFieldID(command_long_class, "param3", "F");
	env->SetFloatField (result, fid, (float)inp.param3);

	fid = env->GetFieldID(command_long_class, "param4", "F");
	env->SetFloatField (result, fid, (float)inp.param4);

	fid = env->GetFieldID(command_long_class, "param5", "F");
	env->SetFloatField (result, fid, (float)inp.param5);

	fid = env->GetFieldID(command_long_class, "param6", "F");
	env->SetFloatField (result, fid, (float)inp.param6);

	fid = env->GetFieldID(command_long_class, "param7", "F");
	env->SetFloatField (result, fid, (float)inp.param7);

	fid = env->GetFieldID(command_long_class, "command", "I");
	env->SetIntField (result, fid, (int) inp.command);

	fid = env->GetFieldID(command_long_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(command_long_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);
/*
	fid = env->GetFieldID(command_long_class, "confirmation", "I");
	env->SetIntField (result, fid, (int) inp.confirmation);
*/

	fid = env->GetFieldID(command_long_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(command_long_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_command_long(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float param1 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param1", "F"));
	float param2 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param2", "F"));
	float param3 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param3", "F"));
	float param4 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param4", "F"));
	float param5 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param5", "F"));
	float param6 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param6", "F"));
	float param7 = (float)env->GetFloatField (obj, env->GetFieldID(command_long_class, "param7", "F"));
	uint16_t command = (uint16_t)env->GetIntField (obj, env->GetFieldID(command_long_class, "command", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(command_long_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(command_long_class, "target_component", "I"));
	uint8_t confirmation = (uint8_t)env->GetIntField (obj, env->GetFieldID(command_long_class, "confirmation", "I"));


	mavlink_msg_command_long_pack(system_id, component_id, &msg,target_system, target_component, command, confirmation, param1, param2, param3, param4, param5, param6, param7);

}

jobject unpack_msg_command_ack(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_command_ack_t inp;
	mavlink_msg_command_ack_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(command_ack_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(command_ack_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(command_ack_class, "command", "I");
	env->SetIntField (result, fid, (int) inp.command);

	fid = env->GetFieldID(command_ack_class, "result", "I");
	env->SetIntField (result, fid, (int) inp.result);


	fid = env->GetFieldID(command_ack_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(command_ack_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_command_ack(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t command = (uint16_t)env->GetIntField (obj, env->GetFieldID(command_ack_class, "command", "I"));
	uint8_t result = (uint8_t)env->GetIntField (obj, env->GetFieldID(command_ack_class, "result", "I"));


	mavlink_msg_command_ack_pack(system_id, component_id, &msg,command, result);

}

jobject unpack_msg_hil_state(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_hil_state_t inp;
	mavlink_msg_hil_state_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(hil_state_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(hil_state_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(hil_state_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(hil_state_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(hil_state_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(hil_state_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(hil_state_class, "rollspeed", "F");
	env->SetFloatField (result, fid, (float)inp.rollspeed);

	fid = env->GetFieldID(hil_state_class, "pitchspeed", "F");
	env->SetFloatField (result, fid, (float)inp.pitchspeed);

	fid = env->GetFieldID(hil_state_class, "yawspeed", "F");
	env->SetFloatField (result, fid, (float)inp.yawspeed);

	fid = env->GetFieldID(hil_state_class, "lat", "J");
	env->SetLongField (result, fid, (long) inp.lat);

	fid = env->GetFieldID(hil_state_class, "lon", "J");
	env->SetLongField (result, fid, (long) inp.lon);

	fid = env->GetFieldID(hil_state_class, "alt", "J");
	env->SetLongField (result, fid, (long) inp.alt);

	fid = env->GetFieldID(hil_state_class, "vx", "I");
	env->SetIntField (result, fid, (int) inp.vx);

	fid = env->GetFieldID(hil_state_class, "vy", "I");
	env->SetIntField (result, fid, (int) inp.vy);

	fid = env->GetFieldID(hil_state_class, "vz", "I");
	env->SetIntField (result, fid, (int) inp.vz);

	fid = env->GetFieldID(hil_state_class, "xacc", "I");
	env->SetIntField (result, fid, (int) inp.xacc);

	fid = env->GetFieldID(hil_state_class, "yacc", "I");
	env->SetIntField (result, fid, (int) inp.yacc);

	fid = env->GetFieldID(hil_state_class, "zacc", "I");
	env->SetIntField (result, fid, (int) inp.zacc);


	fid = env->GetFieldID(hil_state_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(hil_state_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_hil_state(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(hil_state_class, "time_usec", "J"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "yaw", "F"));
	float rollspeed = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "rollspeed", "F"));
	float pitchspeed = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "pitchspeed", "F"));
	float yawspeed = (float)env->GetFloatField (obj, env->GetFieldID(hil_state_class, "yawspeed", "F"));
	int32_t lat = (int32_t)env->GetLongField (obj, env->GetFieldID(hil_state_class, "lat", "J"));
	int32_t lon = (int32_t)env->GetLongField (obj, env->GetFieldID(hil_state_class, "lon", "J"));
	int32_t alt = (int32_t)env->GetLongField (obj, env->GetFieldID(hil_state_class, "alt", "J"));
	int16_t vx = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "vx", "I"));
	int16_t vy = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "vy", "I"));
	int16_t vz = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "vz", "I"));
	int16_t xacc = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "xacc", "I"));
	int16_t yacc = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "yacc", "I"));
	int16_t zacc = (int16_t)env->GetIntField (obj, env->GetFieldID(hil_state_class, "zacc", "I"));


	mavlink_msg_hil_state_pack(system_id, component_id, &msg,time_usec, roll, pitch, yaw, rollspeed, pitchspeed, yawspeed, lat, lon, alt, vx, vy, vz, xacc, yacc, zacc);

}

jobject unpack_msg_hil_controls(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_hil_controls_t inp;
	mavlink_msg_hil_controls_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(hil_controls_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(hil_controls_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(hil_controls_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(hil_controls_class, "roll_ailerons", "F");
	env->SetFloatField (result, fid, (float)inp.roll_ailerons);

	fid = env->GetFieldID(hil_controls_class, "pitch_elevator", "F");
	env->SetFloatField (result, fid, (float)inp.pitch_elevator);

	fid = env->GetFieldID(hil_controls_class, "yaw_rudder", "F");
	env->SetFloatField (result, fid, (float)inp.yaw_rudder);

	fid = env->GetFieldID(hil_controls_class, "throttle", "F");
	env->SetFloatField (result, fid, (float)inp.throttle);

	fid = env->GetFieldID(hil_controls_class, "aux1", "F");
	env->SetFloatField (result, fid, (float)inp.aux1);

	fid = env->GetFieldID(hil_controls_class, "aux2", "F");
	env->SetFloatField (result, fid, (float)inp.aux2);

	fid = env->GetFieldID(hil_controls_class, "aux3", "F");
	env->SetFloatField (result, fid, (float)inp.aux3);

	fid = env->GetFieldID(hil_controls_class, "aux4", "F");
	env->SetFloatField (result, fid, (float)inp.aux4);

	fid = env->GetFieldID(hil_controls_class, "mode", "I");
	env->SetIntField (result, fid, (int) inp.mode);

	fid = env->GetFieldID(hil_controls_class, "nav_mode", "I");
	env->SetIntField (result, fid, (int) inp.nav_mode);


	fid = env->GetFieldID(hil_controls_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(hil_controls_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_hil_controls(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(hil_controls_class, "time_usec", "J"));
	float roll_ailerons = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "roll_ailerons", "F"));
	float pitch_elevator = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "pitch_elevator", "F"));
	float yaw_rudder = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "yaw_rudder", "F"));
	float throttle = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "throttle", "F"));
	float aux1 = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "aux1", "F"));
	float aux2 = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "aux2", "F"));
	float aux3 = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "aux3", "F"));
	float aux4 = (float)env->GetFloatField (obj, env->GetFieldID(hil_controls_class, "aux4", "F"));
	uint8_t mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(hil_controls_class, "mode", "I"));
	uint8_t nav_mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(hil_controls_class, "nav_mode", "I"));


	mavlink_msg_hil_controls_pack(system_id, component_id, &msg,time_usec, roll_ailerons, pitch_elevator, yaw_rudder, throttle, aux1, aux2, aux3, aux4, mode, nav_mode);

}

jobject unpack_msg_hil_rc_inputs_raw(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_hil_rc_inputs_raw_t inp;
	mavlink_msg_hil_rc_inputs_raw_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(hil_rc_inputs_raw_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(hil_rc_inputs_raw_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(hil_rc_inputs_raw_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan1_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan1_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan2_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan2_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan3_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan3_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan4_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan4_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan5_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan5_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan6_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan6_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan7_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan7_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan8_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan8_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan9_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan9_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan10_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan10_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan11_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan11_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "chan12_raw", "I");
	env->SetIntField (result, fid, (int) inp.chan12_raw);

	fid = env->GetFieldID(hil_rc_inputs_raw_class, "rssi", "I");
	env->SetIntField (result, fid, (int) inp.rssi);


	fid = env->GetFieldID(hil_rc_inputs_raw_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(hil_rc_inputs_raw_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_hil_rc_inputs_raw(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "time_usec", "J"));
	uint16_t chan1_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan1_raw", "I"));
	uint16_t chan2_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan2_raw", "I"));
	uint16_t chan3_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan3_raw", "I"));
	uint16_t chan4_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan4_raw", "I"));
	uint16_t chan5_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan5_raw", "I"));
	uint16_t chan6_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan6_raw", "I"));
	uint16_t chan7_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan7_raw", "I"));
	uint16_t chan8_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan8_raw", "I"));
	uint16_t chan9_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan9_raw", "I"));
	uint16_t chan10_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan10_raw", "I"));
	uint16_t chan11_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan11_raw", "I"));
	uint16_t chan12_raw = (uint16_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "chan12_raw", "I"));
	uint8_t rssi = (uint8_t)env->GetIntField (obj, env->GetFieldID(hil_rc_inputs_raw_class, "rssi", "I"));


	mavlink_msg_hil_rc_inputs_raw_pack(system_id, component_id, &msg,time_usec, chan1_raw, chan2_raw, chan3_raw, chan4_raw, chan5_raw, chan6_raw, chan7_raw, chan8_raw, chan9_raw, chan10_raw, chan11_raw, chan12_raw, rssi);

}

jobject unpack_msg_optical_flow(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_optical_flow_t inp;
	mavlink_msg_optical_flow_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(optical_flow_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(optical_flow_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(optical_flow_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(optical_flow_class, "ground_distance", "F");
	env->SetFloatField (result, fid, (float)inp.ground_distance);

	fid = env->GetFieldID(optical_flow_class, "flow_x", "I");
	env->SetIntField (result, fid, (int) inp.flow_x);

	fid = env->GetFieldID(optical_flow_class, "flow_y", "I");
	env->SetIntField (result, fid, (int) inp.flow_y);

	fid = env->GetFieldID(optical_flow_class, "sensor_id", "I");
	env->SetIntField (result, fid, (int) inp.sensor_id);

	fid = env->GetFieldID(optical_flow_class, "quality", "I");
	env->SetIntField (result, fid, (int) inp.quality);


	fid = env->GetFieldID(optical_flow_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(optical_flow_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_optical_flow(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	/*
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(optical_flow_class, "time_usec", "J"));
	float ground_distance = (float)env->GetFloatField (obj, env->GetFieldID(optical_flow_class, "ground_distance", "F"));
	int16_t flow_x = (int16_t)env->GetIntField (obj, env->GetFieldID(optical_flow_class, "flow_x", "I"));
	int16_t flow_y = (int16_t)env->GetIntField (obj, env->GetFieldID(optical_flow_class, "flow_y", "I"));
	uint8_t sensor_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(optical_flow_class, "sensor_id", "I"));
	uint8_t quality = (uint8_t)env->GetIntField (obj, env->GetFieldID(optical_flow_class, "quality", "I"));


	mavlink_msg_optical_flow_pack(system_id, component_id, &msg,time_usec, sensor_id, flow_x, flow_y, quality, ground_distance); */

}

jobject unpack_msg_global_vision_position_estimate(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_global_vision_position_estimate_t inp;
	mavlink_msg_global_vision_position_estimate_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(global_vision_position_estimate_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(global_vision_position_estimate_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(global_vision_position_estimate_class, "usec", "J");
	env->SetLongField (result, fid, (long) inp.usec);

	fid = env->GetFieldID(global_vision_position_estimate_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(global_vision_position_estimate_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(global_vision_position_estimate_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(global_vision_position_estimate_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(global_vision_position_estimate_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(global_vision_position_estimate_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);


	fid = env->GetFieldID(global_vision_position_estimate_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(global_vision_position_estimate_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_global_vision_position_estimate(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(global_vision_position_estimate_class, "usec", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "z", "F"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(global_vision_position_estimate_class, "yaw", "F"));


	mavlink_msg_global_vision_position_estimate_pack(system_id, component_id, &msg,usec, x, y, z, roll, pitch, yaw);

}

jobject unpack_msg_vision_position_estimate(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_vision_position_estimate_t inp;
	mavlink_msg_vision_position_estimate_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(vision_position_estimate_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(vision_position_estimate_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(vision_position_estimate_class, "usec", "J");
	env->SetLongField (result, fid, (long) inp.usec);

	fid = env->GetFieldID(vision_position_estimate_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(vision_position_estimate_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(vision_position_estimate_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(vision_position_estimate_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(vision_position_estimate_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(vision_position_estimate_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);


	fid = env->GetFieldID(vision_position_estimate_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(vision_position_estimate_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_vision_position_estimate(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(vision_position_estimate_class, "usec", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "z", "F"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(vision_position_estimate_class, "yaw", "F"));


	mavlink_msg_vision_position_estimate_pack(system_id, component_id, &msg,usec, x, y, z, roll, pitch, yaw);

}

jobject unpack_msg_vision_speed_estimate(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_vision_speed_estimate_t inp;
	mavlink_msg_vision_speed_estimate_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(vision_speed_estimate_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(vision_speed_estimate_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(vision_speed_estimate_class, "usec", "J");
	env->SetLongField (result, fid, (long) inp.usec);

	fid = env->GetFieldID(vision_speed_estimate_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(vision_speed_estimate_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(vision_speed_estimate_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);


	fid = env->GetFieldID(vision_speed_estimate_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(vision_speed_estimate_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_vision_speed_estimate(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(vision_speed_estimate_class, "usec", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(vision_speed_estimate_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(vision_speed_estimate_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(vision_speed_estimate_class, "z", "F"));


	mavlink_msg_vision_speed_estimate_pack(system_id, component_id, &msg,usec, x, y, z);

}

jobject unpack_msg_vicon_position_estimate(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_vicon_position_estimate_t inp;
	mavlink_msg_vicon_position_estimate_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(vicon_position_estimate_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(vicon_position_estimate_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(vicon_position_estimate_class, "usec", "J");
	env->SetLongField (result, fid, (long) inp.usec);

	fid = env->GetFieldID(vicon_position_estimate_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(vicon_position_estimate_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(vicon_position_estimate_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	fid = env->GetFieldID(vicon_position_estimate_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(vicon_position_estimate_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(vicon_position_estimate_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);


	fid = env->GetFieldID(vicon_position_estimate_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(vicon_position_estimate_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_vicon_position_estimate(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(vicon_position_estimate_class, "usec", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "z", "F"));
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(vicon_position_estimate_class, "yaw", "F"));


	mavlink_msg_vicon_position_estimate_pack(system_id, component_id, &msg,usec, x, y, z, roll, pitch, yaw);

}

jobject unpack_msg_memory_vect(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_memory_vect_t inp;
	mavlink_msg_memory_vect_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(memory_vect_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(memory_vect_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(memory_vect_class, "address", "I");
	env->SetIntField (result, fid, (int) inp.address);

	fid = env->GetFieldID(memory_vect_class, "ver", "I");
	env->SetIntField (result, fid, (int) inp.ver);

	fid = env->GetFieldID(memory_vect_class, "type", "I");
	env->SetIntField (result, fid, (int) inp.type);

	{
		// Lets send it onto Java.
		fid = env->GetFieldID(memory_vect_class, "value", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(result, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 32; i++)
			data[i] = inp.value[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}

	fid = env->GetFieldID(memory_vect_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(memory_vect_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_memory_vect(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t address = (uint16_t)env->GetIntField (obj, env->GetFieldID(memory_vect_class, "address", "I"));
	uint8_t ver = (uint8_t)env->GetIntField (obj, env->GetFieldID(memory_vect_class, "ver", "I"));
	uint8_t type = (uint8_t)env->GetIntField (obj, env->GetFieldID(memory_vect_class, "type", "I"));
int8_t value[32];
	{
	jfieldID fid;
		// Lets send it onto Java.
		fid = env->GetFieldID(memory_vect_class, "value", "[I");
		jintArray intArr = (jintArray) env->GetObjectField(obj, fid);
		jint* data = env->GetIntArrayElements(intArr, NULL);
		for(int i = 0; i < 32; i++)
			value[i] = data[i];

		//Don't forget to release it
		env->ReleaseIntArrayElements(intArr, data, 0);
	}


	mavlink_msg_memory_vect_pack(system_id, component_id, &msg,address, ver, type, value);

}

jobject unpack_msg_debug_vect(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_debug_vect_t inp;
	mavlink_msg_debug_vect_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(debug_vect_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(debug_vect_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(debug_vect_class, "time_usec", "J");
	env->SetLongField (result, fid, (long) inp.time_usec);

	fid = env->GetFieldID(debug_vect_class, "x", "F");
	env->SetFloatField (result, fid, (float)inp.x);

	fid = env->GetFieldID(debug_vect_class, "y", "F");
	env->SetFloatField (result, fid, (float)inp.y);

	fid = env->GetFieldID(debug_vect_class, "z", "F");
	env->SetFloatField (result, fid, (float)inp.z);

	{
		fid = env->GetFieldID(debug_vect_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			data[i] = inp.name[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(debug_vect_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(debug_vect_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_debug_vect(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint64_t time_usec = (uint64_t)env->GetLongField (obj, env->GetFieldID(debug_vect_class, "time_usec", "J"));
	float x = (float)env->GetFloatField (obj, env->GetFieldID(debug_vect_class, "x", "F"));
	float y = (float)env->GetFloatField (obj, env->GetFieldID(debug_vect_class, "y", "F"));
	float z = (float)env->GetFloatField (obj, env->GetFieldID(debug_vect_class, "z", "F"));
	char name[10];
	{
	jfieldID fid;
		fid = env->GetFieldID(debug_vect_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			name[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_debug_vect_pack(system_id, component_id, &msg,name, time_usec, x, y, z);

}

jobject unpack_msg_named_value_float(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_named_value_float_t inp;
	mavlink_msg_named_value_float_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(named_value_float_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(named_value_float_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(named_value_float_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(named_value_float_class, "value", "F");
	env->SetFloatField (result, fid, (float)inp.value);

	{
		fid = env->GetFieldID(named_value_float_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			data[i] = inp.name[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(named_value_float_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(named_value_float_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_named_value_float(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(named_value_float_class, "time_boot_ms", "J"));
	float value = (float)env->GetFloatField (obj, env->GetFieldID(named_value_float_class, "value", "F"));
	char name[10];
	{
	jfieldID fid;
		fid = env->GetFieldID(named_value_float_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			name[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_named_value_float_pack(system_id, component_id, &msg,time_boot_ms, name, value);

}

jobject unpack_msg_named_value_int(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_named_value_int_t inp;
	mavlink_msg_named_value_int_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(named_value_int_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(named_value_int_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(named_value_int_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(named_value_int_class, "value", "J");
	env->SetLongField (result, fid, (long) inp.value);

	{
		fid = env->GetFieldID(named_value_int_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			data[i] = inp.name[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(named_value_int_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(named_value_int_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_named_value_int(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(named_value_int_class, "time_boot_ms", "J"));
	int32_t value = (int32_t)env->GetLongField (obj, env->GetFieldID(named_value_int_class, "value", "J"));
	char name[10];
	{
	jfieldID fid;
		fid = env->GetFieldID(named_value_int_class, "name", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 10; i++)
			name[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_named_value_int_pack(system_id, component_id, &msg,time_boot_ms, name, value);

}

jobject unpack_msg_statustext(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_statustext_t inp;
	mavlink_msg_statustext_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(statustext_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(statustext_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(statustext_class, "severity", "I");
	env->SetIntField (result, fid, (int) inp.severity);

	{
		fid = env->GetFieldID(statustext_class, "text", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(result, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 50; i++)
			data[i] = inp.text[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}

	fid = env->GetFieldID(statustext_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(statustext_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_statustext(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t severity = (uint8_t)env->GetIntField (obj, env->GetFieldID(statustext_class, "severity", "I"));
	char text[50];
	{
	jfieldID fid;
		fid = env->GetFieldID(statustext_class, "text", "[C");
		jcharArray charArr = (jcharArray) env->GetObjectField(obj, fid);
		jchar* data = env->GetCharArrayElements(charArr, NULL);
		for(int i = 0; i < 50; i++)
			text[i] = data[i];

		// Don't forget to release it
		env->ReleaseCharArrayElements(charArr, data, 0);
	}


	mavlink_msg_statustext_pack(system_id, component_id, &msg,severity, text);

}

jobject unpack_msg_debug(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_debug_t inp;
	mavlink_msg_debug_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(debug_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(debug_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(debug_class, "time_boot_ms", "J");
	env->SetLongField (result, fid, (long) inp.time_boot_ms);

	fid = env->GetFieldID(debug_class, "value", "F");
	env->SetFloatField (result, fid, (float)inp.value);

	fid = env->GetFieldID(debug_class, "ind", "I");
	env->SetIntField (result, fid, (int) inp.ind);


	fid = env->GetFieldID(debug_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(debug_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_debug(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t time_boot_ms = (uint32_t)env->GetLongField (obj, env->GetFieldID(debug_class, "time_boot_ms", "J"));
	float value = (float)env->GetFloatField (obj, env->GetFieldID(debug_class, "value", "F"));
	uint8_t ind = (uint8_t)env->GetIntField (obj, env->GetFieldID(debug_class, "ind", "I"));


	mavlink_msg_debug_pack(system_id, component_id, &msg,time_boot_ms, ind, value);

}

jobject unpack_msg_extended_message(JNIEnv *env, mavlink_message_t& message){
	/*
	jclass newMessage;
	mavlink_extended_message_t inp;
	mavlink_msg_extended_message_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(extended_message_class, "<init>", "()V");
	if (cid == NULL) return NULL;
	jobject result = env->NewObject(extended_message_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(extended_message_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(extended_message_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(extended_message_class, "protocol_flags", "I");
	env->SetIntField (result, fid, (int) inp.protocol_flags);


	fid = env->GetFieldID(extended_message_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(extended_message_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return NULL;

}

void pack_msg_extended_message(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	/*
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(extended_message_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(extended_message_class, "target_component", "I"));
	uint8_t protocol_flags = (uint8_t)env->GetIntField (obj, env->GetFieldID(extended_message_class, "protocol_flags", "I"));


	mavlink_msg_extended_message_pack(system_id, component_id, &msg,target_system, target_component, protocol_flags);*/

}

jobject unpack_msg_sensor_offsets(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_sensor_offsets_t inp;
	mavlink_msg_sensor_offsets_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(sensor_offsets_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(sensor_offsets_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(sensor_offsets_class, "mag_declination", "F");
	env->SetFloatField (result, fid, (float)inp.mag_declination);

	fid = env->GetFieldID(sensor_offsets_class, "raw_press", "J");
	env->SetLongField (result, fid, (long) inp.raw_press);

	fid = env->GetFieldID(sensor_offsets_class, "raw_temp", "J");
	env->SetLongField (result, fid, (long) inp.raw_temp);

	fid = env->GetFieldID(sensor_offsets_class, "gyro_cal_x", "F");
	env->SetFloatField (result, fid, (float)inp.gyro_cal_x);

	fid = env->GetFieldID(sensor_offsets_class, "gyro_cal_y", "F");
	env->SetFloatField (result, fid, (float)inp.gyro_cal_y);

	fid = env->GetFieldID(sensor_offsets_class, "gyro_cal_z", "F");
	env->SetFloatField (result, fid, (float)inp.gyro_cal_z);

	fid = env->GetFieldID(sensor_offsets_class, "accel_cal_x", "F");
	env->SetFloatField (result, fid, (float)inp.accel_cal_x);

	fid = env->GetFieldID(sensor_offsets_class, "accel_cal_y", "F");
	env->SetFloatField (result, fid, (float)inp.accel_cal_y);

	fid = env->GetFieldID(sensor_offsets_class, "accel_cal_z", "F");
	env->SetFloatField (result, fid, (float)inp.accel_cal_z);

	fid = env->GetFieldID(sensor_offsets_class, "mag_ofs_x", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_x);

	fid = env->GetFieldID(sensor_offsets_class, "mag_ofs_y", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_y);

	fid = env->GetFieldID(sensor_offsets_class, "mag_ofs_z", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_z);


	fid = env->GetFieldID(sensor_offsets_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(sensor_offsets_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_sensor_offsets(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float mag_declination = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "mag_declination", "F"));
	int32_t raw_press = (int32_t)env->GetLongField (obj, env->GetFieldID(sensor_offsets_class, "raw_press", "J"));
	int32_t raw_temp = (int32_t)env->GetLongField (obj, env->GetFieldID(sensor_offsets_class, "raw_temp", "J"));
	float gyro_cal_x = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "gyro_cal_x", "F"));
	float gyro_cal_y = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "gyro_cal_y", "F"));
	float gyro_cal_z = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "gyro_cal_z", "F"));
	float accel_cal_x = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "accel_cal_x", "F"));
	float accel_cal_y = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "accel_cal_y", "F"));
	float accel_cal_z = (float)env->GetFloatField (obj, env->GetFieldID(sensor_offsets_class, "accel_cal_z", "F"));
	int16_t mag_ofs_x = (int16_t)env->GetIntField (obj, env->GetFieldID(sensor_offsets_class, "mag_ofs_x", "I"));
	int16_t mag_ofs_y = (int16_t)env->GetIntField (obj, env->GetFieldID(sensor_offsets_class, "mag_ofs_y", "I"));
	int16_t mag_ofs_z = (int16_t)env->GetIntField (obj, env->GetFieldID(sensor_offsets_class, "mag_ofs_z", "I"));


	mavlink_msg_sensor_offsets_pack(system_id, component_id, &msg,mag_ofs_x, mag_ofs_y, mag_ofs_z, mag_declination, raw_press, raw_temp, gyro_cal_x, gyro_cal_y, gyro_cal_z, accel_cal_x, accel_cal_y, accel_cal_z);

}

jobject unpack_msg_set_mag_offsets(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_set_mag_offsets_t inp;
	mavlink_msg_set_mag_offsets_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(set_mag_offsets_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(set_mag_offsets_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(set_mag_offsets_class, "mag_ofs_x", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_x);

	fid = env->GetFieldID(set_mag_offsets_class, "mag_ofs_y", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_y);

	fid = env->GetFieldID(set_mag_offsets_class, "mag_ofs_z", "I");
	env->SetIntField (result, fid, (int) inp.mag_ofs_z);

	fid = env->GetFieldID(set_mag_offsets_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(set_mag_offsets_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(set_mag_offsets_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(set_mag_offsets_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_set_mag_offsets(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int16_t mag_ofs_x = (int16_t)env->GetIntField (obj, env->GetFieldID(set_mag_offsets_class, "mag_ofs_x", "I"));
	int16_t mag_ofs_y = (int16_t)env->GetIntField (obj, env->GetFieldID(set_mag_offsets_class, "mag_ofs_y", "I"));
	int16_t mag_ofs_z = (int16_t)env->GetIntField (obj, env->GetFieldID(set_mag_offsets_class, "mag_ofs_z", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_mag_offsets_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(set_mag_offsets_class, "target_component", "I"));


	mavlink_msg_set_mag_offsets_pack(system_id, component_id, &msg,target_system, target_component, mag_ofs_x, mag_ofs_y, mag_ofs_z);

}

jobject unpack_msg_meminfo(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_meminfo_t inp;
	mavlink_msg_meminfo_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(meminfo_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(meminfo_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(meminfo_class, "brkval", "I");
	env->SetIntField (result, fid, (int) inp.brkval);

	fid = env->GetFieldID(meminfo_class, "freemem", "I");
	env->SetIntField (result, fid, (int) inp.freemem);


	fid = env->GetFieldID(meminfo_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(meminfo_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_meminfo(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t brkval = (uint16_t)env->GetIntField (obj, env->GetFieldID(meminfo_class, "brkval", "I"));
	uint16_t freemem = (uint16_t)env->GetIntField (obj, env->GetFieldID(meminfo_class, "freemem", "I"));


	mavlink_msg_meminfo_pack(system_id, component_id, &msg,brkval, freemem);

}

jobject unpack_msg_ap_adc(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_ap_adc_t inp;
	mavlink_msg_ap_adc_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(ap_adc_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(ap_adc_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(ap_adc_class, "adc1", "I");
	env->SetIntField (result, fid, (int) inp.adc1);

	fid = env->GetFieldID(ap_adc_class, "adc2", "I");
	env->SetIntField (result, fid, (int) inp.adc2);

	fid = env->GetFieldID(ap_adc_class, "adc3", "I");
	env->SetIntField (result, fid, (int) inp.adc3);

	fid = env->GetFieldID(ap_adc_class, "adc4", "I");
	env->SetIntField (result, fid, (int) inp.adc4);

	fid = env->GetFieldID(ap_adc_class, "adc5", "I");
	env->SetIntField (result, fid, (int) inp.adc5);

	fid = env->GetFieldID(ap_adc_class, "adc6", "I");
	env->SetIntField (result, fid, (int) inp.adc6);


	fid = env->GetFieldID(ap_adc_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(ap_adc_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_ap_adc(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t adc1 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc1", "I"));
	uint16_t adc2 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc2", "I"));
	uint16_t adc3 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc3", "I"));
	uint16_t adc4 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc4", "I"));
	uint16_t adc5 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc5", "I"));
	uint16_t adc6 = (uint16_t)env->GetIntField (obj, env->GetFieldID(ap_adc_class, "adc6", "I"));


	mavlink_msg_ap_adc_pack(system_id, component_id, &msg,adc1, adc2, adc3, adc4, adc5, adc6);

}

jobject unpack_msg_digicam_configure(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_digicam_configure_t inp;
	mavlink_msg_digicam_configure_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(digicam_configure_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(digicam_configure_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(digicam_configure_class, "extra_value", "F");
	env->SetFloatField (result, fid, (float)inp.extra_value);

	fid = env->GetFieldID(digicam_configure_class, "shutter_speed", "I");
	env->SetIntField (result, fid, (int) inp.shutter_speed);

	fid = env->GetFieldID(digicam_configure_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(digicam_configure_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(digicam_configure_class, "mode", "I");
	env->SetIntField (result, fid, (int) inp.mode);

	fid = env->GetFieldID(digicam_configure_class, "aperture", "I");
	env->SetIntField (result, fid, (int) inp.aperture);

	fid = env->GetFieldID(digicam_configure_class, "iso", "I");
	env->SetIntField (result, fid, (int) inp.iso);

	fid = env->GetFieldID(digicam_configure_class, "exposure_type", "I");
	env->SetIntField (result, fid, (int) inp.exposure_type);

	fid = env->GetFieldID(digicam_configure_class, "command_id", "I");
	env->SetIntField (result, fid, (int) inp.command_id);

	fid = env->GetFieldID(digicam_configure_class, "engine_cut_off", "I");
	env->SetIntField (result, fid, (int) inp.engine_cut_off);

	fid = env->GetFieldID(digicam_configure_class, "extra_param", "I");
	env->SetIntField (result, fid, (int) inp.extra_param);


	fid = env->GetFieldID(digicam_configure_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(digicam_configure_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_digicam_configure(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float extra_value = (float)env->GetFloatField (obj, env->GetFieldID(digicam_configure_class, "extra_value", "F"));
	uint16_t shutter_speed = (uint16_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "shutter_speed", "I"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "target_component", "I"));
	uint8_t mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "mode", "I"));
	uint8_t aperture = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "aperture", "I"));
	uint8_t iso = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "iso", "I"));
	uint8_t exposure_type = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "exposure_type", "I"));
	uint8_t command_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "command_id", "I"));
	uint8_t engine_cut_off = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "engine_cut_off", "I"));
	uint8_t extra_param = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_configure_class, "extra_param", "I"));


	mavlink_msg_digicam_configure_pack(system_id, component_id, &msg,target_system, target_component, mode, shutter_speed, aperture, iso, exposure_type, command_id, engine_cut_off, extra_param, extra_value);

}

jobject unpack_msg_digicam_control(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_digicam_control_t inp;
	mavlink_msg_digicam_control_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(digicam_control_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(digicam_control_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(digicam_control_class, "extra_value", "F");
	env->SetFloatField (result, fid, (float)inp.extra_value);

	fid = env->GetFieldID(digicam_control_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(digicam_control_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(digicam_control_class, "session", "I");
	env->SetIntField (result, fid, (int) inp.session);

	fid = env->GetFieldID(digicam_control_class, "zoom_pos", "I");
	env->SetIntField (result, fid, (int) inp.zoom_pos);

	fid = env->GetFieldID(digicam_control_class, "zoom_step", "I");
	env->SetIntField (result, fid, (int) inp.zoom_step);

	fid = env->GetFieldID(digicam_control_class, "focus_lock", "I");
	env->SetIntField (result, fid, (int) inp.focus_lock);

	fid = env->GetFieldID(digicam_control_class, "shot", "I");
	env->SetIntField (result, fid, (int) inp.shot);

	fid = env->GetFieldID(digicam_control_class, "command_id", "I");
	env->SetIntField (result, fid, (int) inp.command_id);

	fid = env->GetFieldID(digicam_control_class, "extra_param", "I");
	env->SetIntField (result, fid, (int) inp.extra_param);


	fid = env->GetFieldID(digicam_control_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(digicam_control_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_digicam_control(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float extra_value = (float)env->GetFloatField (obj, env->GetFieldID(digicam_control_class, "extra_value", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "target_component", "I"));
	uint8_t session = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "session", "I"));
	uint8_t zoom_pos = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "zoom_pos", "I"));
	int8_t zoom_step = (int8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "zoom_step", "I"));
	uint8_t focus_lock = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "focus_lock", "I"));
	uint8_t shot = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "shot", "I"));
	uint8_t command_id = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "command_id", "I"));
	uint8_t extra_param = (uint8_t)env->GetIntField (obj, env->GetFieldID(digicam_control_class, "extra_param", "I"));


	mavlink_msg_digicam_control_pack(system_id, component_id, &msg,target_system, target_component, session, zoom_pos, zoom_step, focus_lock, shot, command_id, extra_param, extra_value);

}

jobject unpack_msg_mount_configure(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mount_configure_t inp;
	mavlink_msg_mount_configure_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mount_configure_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mount_configure_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mount_configure_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mount_configure_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(mount_configure_class, "mount_mode", "I");
	env->SetIntField (result, fid, (int) inp.mount_mode);

	fid = env->GetFieldID(mount_configure_class, "stab_roll", "I");
	env->SetIntField (result, fid, (int) inp.stab_roll);

	fid = env->GetFieldID(mount_configure_class, "stab_pitch", "I");
	env->SetIntField (result, fid, (int) inp.stab_pitch);

	fid = env->GetFieldID(mount_configure_class, "stab_yaw", "I");
	env->SetIntField (result, fid, (int) inp.stab_yaw);


	fid = env->GetFieldID(mount_configure_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mount_configure_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mount_configure(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "target_component", "I"));
	uint8_t mount_mode = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "mount_mode", "I"));
	uint8_t stab_roll = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "stab_roll", "I"));
	uint8_t stab_pitch = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "stab_pitch", "I"));
	uint8_t stab_yaw = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_configure_class, "stab_yaw", "I"));


	mavlink_msg_mount_configure_pack(system_id, component_id, &msg,target_system, target_component, mount_mode, stab_roll, stab_pitch, stab_yaw);

}

jobject unpack_msg_mount_control(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mount_control_t inp;
	mavlink_msg_mount_control_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mount_control_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mount_control_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mount_control_class, "input_a", "J");
	env->SetLongField (result, fid, (long) inp.input_a);

	fid = env->GetFieldID(mount_control_class, "input_b", "J");
	env->SetLongField (result, fid, (long) inp.input_b);

	fid = env->GetFieldID(mount_control_class, "input_c", "J");
	env->SetLongField (result, fid, (long) inp.input_c);

	fid = env->GetFieldID(mount_control_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mount_control_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(mount_control_class, "save_position", "I");
	env->SetIntField (result, fid, (int) inp.save_position);


	fid = env->GetFieldID(mount_control_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mount_control_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mount_control(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t input_a = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_control_class, "input_a", "J"));
	int32_t input_b = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_control_class, "input_b", "J"));
	int32_t input_c = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_control_class, "input_c", "J"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_control_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_control_class, "target_component", "I"));
	uint8_t save_position = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_control_class, "save_position", "I"));


	mavlink_msg_mount_control_pack(system_id, component_id, &msg,target_system, target_component, input_a, input_b, input_c, save_position);

}

jobject unpack_msg_mount_status(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_mount_status_t inp;
	mavlink_msg_mount_status_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(mount_status_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(mount_status_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(mount_status_class, "pointing_a", "J");
	env->SetLongField (result, fid, (long) inp.pointing_a);

	fid = env->GetFieldID(mount_status_class, "pointing_b", "J");
	env->SetLongField (result, fid, (long) inp.pointing_b);

	fid = env->GetFieldID(mount_status_class, "pointing_c", "J");
	env->SetLongField (result, fid, (long) inp.pointing_c);

	fid = env->GetFieldID(mount_status_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(mount_status_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);


	fid = env->GetFieldID(mount_status_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(mount_status_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_mount_status(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	int32_t pointing_a = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_status_class, "pointing_a", "J"));
	int32_t pointing_b = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_status_class, "pointing_b", "J"));
	int32_t pointing_c = (int32_t)env->GetLongField (obj, env->GetFieldID(mount_status_class, "pointing_c", "J"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_status_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(mount_status_class, "target_component", "I"));


	mavlink_msg_mount_status_pack(system_id, component_id, &msg,target_system, target_component, pointing_a, pointing_b, pointing_c);

}

jobject unpack_msg_fence_point(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_fence_point_t inp;
	mavlink_msg_fence_point_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(fence_point_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(fence_point_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(fence_point_class, "lat", "F");
	env->SetFloatField (result, fid, (float)inp.lat);

	fid = env->GetFieldID(fence_point_class, "lng", "F");
	env->SetFloatField (result, fid, (float)inp.lng);

	fid = env->GetFieldID(fence_point_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(fence_point_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(fence_point_class, "idx", "I");
	env->SetIntField (result, fid, (int) inp.idx);

	fid = env->GetFieldID(fence_point_class, "count", "I");
	env->SetIntField (result, fid, (int) inp.count);


	fid = env->GetFieldID(fence_point_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(fence_point_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_fence_point(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float lat = (float)env->GetFloatField (obj, env->GetFieldID(fence_point_class, "lat", "F"));
	float lng = (float)env->GetFloatField (obj, env->GetFieldID(fence_point_class, "lng", "F"));
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_point_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_point_class, "target_component", "I"));
	uint8_t idx = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_point_class, "idx", "I"));
	uint8_t count = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_point_class, "count", "I"));


	mavlink_msg_fence_point_pack(system_id, component_id, &msg,target_system, target_component, idx, count, lat, lng);

}

jobject unpack_msg_fence_fetch_point(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_fence_fetch_point_t inp;
	mavlink_msg_fence_fetch_point_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(fence_fetch_point_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(fence_fetch_point_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(fence_fetch_point_class, "target_system", "I");
	env->SetIntField (result, fid, (int) inp.target_system);

	fid = env->GetFieldID(fence_fetch_point_class, "target_component", "I");
	env->SetIntField (result, fid, (int) inp.target_component);

	fid = env->GetFieldID(fence_fetch_point_class, "idx", "I");
	env->SetIntField (result, fid, (int) inp.idx);


	fid = env->GetFieldID(fence_fetch_point_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(fence_fetch_point_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_fence_fetch_point(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint8_t target_system = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_fetch_point_class, "target_system", "I"));
	uint8_t target_component = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_fetch_point_class, "target_component", "I"));
	uint8_t idx = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_fetch_point_class, "idx", "I"));


	mavlink_msg_fence_fetch_point_pack(system_id, component_id, &msg,target_system, target_component, idx);

}

jobject unpack_msg_fence_status(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_fence_status_t inp;
	mavlink_msg_fence_status_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(fence_status_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(fence_status_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(fence_status_class, "breach_time", "J");
	env->SetLongField (result, fid, (long) inp.breach_time);

	fid = env->GetFieldID(fence_status_class, "breach_count", "I");
	env->SetIntField (result, fid, (int) inp.breach_count);

	fid = env->GetFieldID(fence_status_class, "breach_status", "I");
	env->SetIntField (result, fid, (int) inp.breach_status);

	fid = env->GetFieldID(fence_status_class, "breach_type", "I");
	env->SetIntField (result, fid, (int) inp.breach_type);


	fid = env->GetFieldID(fence_status_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(fence_status_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_fence_status(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint32_t breach_time = (uint32_t)env->GetLongField (obj, env->GetFieldID(fence_status_class, "breach_time", "J"));
	uint16_t breach_count = (uint16_t)env->GetIntField (obj, env->GetFieldID(fence_status_class, "breach_count", "I"));
	uint8_t breach_status = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_status_class, "breach_status", "I"));
	uint8_t breach_type = (uint8_t)env->GetIntField (obj, env->GetFieldID(fence_status_class, "breach_type", "I"));


	mavlink_msg_fence_status_pack(system_id, component_id, &msg,breach_status, breach_count, breach_type, breach_time);

}

jobject unpack_msg_ahrs(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_ahrs_t inp;
	mavlink_msg_ahrs_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(ahrs_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(ahrs_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(ahrs_class, "omegaIx", "F");
	env->SetFloatField (result, fid, (float)inp.omegaIx);

	fid = env->GetFieldID(ahrs_class, "omegaIy", "F");
	env->SetFloatField (result, fid, (float)inp.omegaIy);

	fid = env->GetFieldID(ahrs_class, "omegaIz", "F");
	env->SetFloatField (result, fid, (float)inp.omegaIz);

	fid = env->GetFieldID(ahrs_class, "accel_weight", "F");
	env->SetFloatField (result, fid, (float)inp.accel_weight);

	fid = env->GetFieldID(ahrs_class, "renorm_val", "F");
	env->SetFloatField (result, fid, (float)inp.renorm_val);

	fid = env->GetFieldID(ahrs_class, "error_rp", "F");
	env->SetFloatField (result, fid, (float)inp.error_rp);

	fid = env->GetFieldID(ahrs_class, "error_yaw", "F");
	env->SetFloatField (result, fid, (float)inp.error_yaw);


	fid = env->GetFieldID(ahrs_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(ahrs_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_ahrs(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	float omegaIx = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "omegaIx", "F"));
	float omegaIy = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "omegaIy", "F"));
	float omegaIz = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "omegaIz", "F"));
	float accel_weight = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "accel_weight", "F"));
	float renorm_val = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "renorm_val", "F"));
	float error_rp = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "error_rp", "F"));
	float error_yaw = (float)env->GetFloatField (obj, env->GetFieldID(ahrs_class, "error_yaw", "F"));


	mavlink_msg_ahrs_pack(system_id, component_id, &msg,omegaIx, omegaIy, omegaIz, accel_weight, renorm_val, error_rp, error_yaw);

}

jobject unpack_msg_simstate(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_simstate_t inp;
	mavlink_msg_simstate_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(simstate_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(simstate_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(simstate_class, "roll", "F");
	env->SetFloatField (result, fid, (float)inp.roll);

	fid = env->GetFieldID(simstate_class, "pitch", "F");
	env->SetFloatField (result, fid, (float)inp.pitch);

	fid = env->GetFieldID(simstate_class, "yaw", "F");
	env->SetFloatField (result, fid, (float)inp.yaw);

	fid = env->GetFieldID(simstate_class, "xacc", "F");
	env->SetFloatField (result, fid, (float)inp.xacc);

	fid = env->GetFieldID(simstate_class, "yacc", "F");
	env->SetFloatField (result, fid, (float)inp.yacc);

	fid = env->GetFieldID(simstate_class, "zacc", "F");
	env->SetFloatField (result, fid, (float)inp.zacc);

	fid = env->GetFieldID(simstate_class, "xgyro", "F");
	env->SetFloatField (result, fid, (float)inp.xgyro);

	fid = env->GetFieldID(simstate_class, "ygyro", "F");
	env->SetFloatField (result, fid, (float)inp.ygyro);

	fid = env->GetFieldID(simstate_class, "zgyro", "F");
	env->SetFloatField (result, fid, (float)inp.zgyro);


	fid = env->GetFieldID(simstate_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(simstate_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_simstate(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	/*
	float roll = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "roll", "F"));
	float pitch = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "pitch", "F"));
	float yaw = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "yaw", "F"));
	float xacc = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "xacc", "F"));
	float yacc = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "yacc", "F"));
	float zacc = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "zacc", "F"));
	float xgyro = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "xgyro", "F"));
	float ygyro = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "ygyro", "F"));
	float zgyro = (float)env->GetFloatField (obj, env->GetFieldID(simstate_class, "zgyro", "F"));


	mavlink_msg_simstate_pack(system_id, component_id, &msg,roll, pitch, yaw, xacc, yacc, zacc, xgyro, ygyro, zgyro);
*/
}

jobject unpack_msg_hwstatus(JNIEnv *env, mavlink_message_t& message){

	jclass newMessage;
	mavlink_hwstatus_t inp;
	mavlink_msg_hwstatus_decode(&message, &inp);

	// Create the object
	jmethodID cid = env->GetMethodID(hwstatus_class, "<init>", "()V");
	if (cid == NULL) return NULL; /* exception thrown */
	jobject result = env->NewObject(hwstatus_class, cid);


	//Set values
	jfieldID fid;
	fid = env->GetFieldID(hwstatus_class, "Vcc", "I");
	env->SetIntField (result, fid, (int) inp.Vcc);

	fid = env->GetFieldID(hwstatus_class, "I2Cerr", "I");
	env->SetIntField (result, fid, (int) inp.I2Cerr);


	fid = env->GetFieldID(hwstatus_class, "sysID", "I");
	env->SetIntField (result, fid, (int) message.sysid);
	fid = env->GetFieldID(hwstatus_class, "componentID", "I");
	env->SetIntField (result, fid, (int) message.compid);
	/* Free local references */
	//env->DeleteLocalRef(heartbeatClass);

	return result;

}

void pack_msg_hwstatus(JNIEnv *env, jclass& classType, jobject& obj, mavlink_message_t& msg){
	uint16_t Vcc = (uint16_t)env->GetIntField (obj, env->GetFieldID(hwstatus_class, "Vcc", "I"));
	uint8_t I2Cerr = (uint8_t)env->GetIntField (obj, env->GetFieldID(hwstatus_class, "I2Cerr", "I"));


	mavlink_msg_hwstatus_pack(system_id, component_id, &msg,Vcc, I2Cerr);

}

