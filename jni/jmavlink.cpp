#include "mavlink/include/common/mavlink.h"
#include "mavlink/include/ardupilotmega/ardupilotmega.h"


#include "mavlink/include_v1.0/common/mavlink.h"
#include "mavlink/include_v1.0/ardupilotmega/ardupilotmega.h"


#include <string.h>
#include <jni.h>
#include <android/log.h>

// Declare each of the known java classes
#include "classDeclarations.h"
jclass interface_class;

// Declare each of the parser functions.
// These convert from a MAVLink C message to the java equivalent.
#include "parseFunctions.h"

#ifndef _Included_eu_powet_groundcopter_MavlinkNative
#define _Included_eu_powet_groundcopter_MavlinkNative
#ifdef __cplusplus
extern "C" {
#endif
#undef eu_powet_groundcopter_MavlinkNative_serialVersionUID
#define eu_powet_groundcopter_MavlinkNative_serialVersionUID 5516075349620653480LL
#undef eu_powet_groundcopter_MavlinkNative_serialVersionUID
#define eu_powet_groundcopter_MavlinkNative_serialVersionUID 1LL

#define TAG "JNI_MAVLINK"
static JavaVM* g_vm = NULL;

jobject g_obj;
jmethodID g_mid;

int silent = 0; ///< Wether console output should be enabled
int verbose = 0; ///< Enable verbose output
int debug = 0; ///< Enable debug functions and output

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* jvm, void* reserved)
{
	g_vm = jvm;
	return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL Java_eu_powet_groundcopter_MavlinkNative_registerCallbacks
  (JNIEnv *env, jobject obj)
{
	// convert local to global reference
	g_obj = env->NewGlobalRef(obj);
	// save refs for callback
	jclass g_clazz = env->GetObjectClass(g_obj);

	if (g_clazz == NULL)
	{
		__android_log_print(ANDROID_LOG_ERROR, TAG, "Failed to find class \n");
	}

	g_mid = env->GetMethodID(g_clazz, "postEventFromNative","(Ljava/lang/Object;)V");
	if (g_mid == NULL)
	{
		__android_log_print(ANDROID_LOG_ERROR, TAG, "Unable to get method ref");
	}

}


void fire_msg(jobject obj)
{
	if(obj == NULL)
	{
		__android_log_print(ANDROID_LOG_ERROR, TAG, "\t fire_msg NULL \n");

	}else {


	JNIEnv * g_env;
	int getEnvStat = g_vm->GetEnv((void **)&g_env, JNI_VERSION_1_6);

	if (getEnvStat == JNI_EDETACHED)
	{
		if (g_vm->AttachCurrentThread((JNIEnv **) &g_env, NULL) != 0)
		{
			//   printf("Failed to attach\n");
		}
	} else if (getEnvStat == JNI_OK)
	{
		//
	} else if (getEnvStat == JNI_EVERSION)
	{
		//printf("GetEnv: version not supported\n");
	}

	g_env->CallVoidMethod(g_obj, g_mid, obj);
	}
}


JNIEXPORT void JNICALL Java_eu_powet_groundcopter_MavlinkNative_forward (JNIEnv *env, jclass obj, jint len, jbyteArray data)
{
	//	__android_log_print(ANDROID_LOG_DEBUG, TAG, "foward %d", len);
	char cp;
	mavlink_message_t message;
	mavlink_status_t status;
	uint8_t msgReceived = 0;
	mavlink_status_t lastStatus;
	lastStatus.packet_rx_drop_count = 0;
	int i;
	jbyte* msg = (jbyte *)malloc(len * sizeof(jbyte));
	env->GetByteArrayRegion(data,0,len,msg);
	#include "classLoader.h"
	for(i=0;i<len;i++)
	{
		cp = msg[i];
		// Check if a message could be decoded, return the message in case yes
		msgReceived = mavlink_parse_char(MAVLINK_COMM_1, cp, &message, &status);
		if (lastStatus.packet_rx_drop_count != status.packet_rx_drop_count)
		{
			if (verbose || debug)
				__android_log_print(ANDROID_LOG_ERROR, TAG, "ERROR: DROPPED %d PACKETS\n", status.packet_rx_drop_count);
			if (debug)
			{
				unsigned char v=cp;
				__android_log_print(ANDROID_LOG_ERROR, TAG, "%02x ", v);
			}
		}
		lastStatus = status;


		if(msgReceived)
		{

			//__android_log_print(ANDROID_LOG_DEBUG, TAG, "\t message.msgid : %d\n",message.msgid);
	    	jobject result;
			switch (message.msgid)
			{

			#include "switchReceive.h"

			} // switch

		}//if

	}
}

JNIEXPORT jbyteArray JNICALL Java_eu_powet_groundcopter_MavlinkNative_createMessage  (JNIEnv *env, jclass c, jobject obj)
{
	interface_class =  env->FindClass("com/mavlink/messages/IMAVLinkMessage");
	#include "classLoader.h"
	int parsed = 0;
	mavlink_message_t msg;
	int messageType = env->GetIntField (obj, env->GetFieldID(interface_class, "messageType", "I"));

	//__android_log_print(ANDROID_LOG_DEBUG, TAG, "\t messageType : %d\n",messageType);

	switch(messageType)
	{
		#include "packSelection.h"
	}
	//---------------------------------------------------------------
		// Off it goes.
		if(parsed){
			uint8_t buffer[MAVLINK_MAX_PACKET_LEN];

			// Write message into buffer, prepending start sign
			int len = mavlink_msg_to_send_buffer(buffer, &msg);

			// Lets send it onto Java.
			jbyteArray jb = env->NewByteArray(len);

			// Get the elements (you probably have to fetch the length of the array as well
			jbyte* data = env->GetByteArrayElements(jb, NULL);

			for(int i = 0; i < len; i++)
				data[i] = buffer[i];

			// Don't forget to release it
			env->ReleaseByteArrayElements(jb, data, 0);

			return (jb);
		}

		return NULL;
}


#ifdef __cplusplus
}
#endif
#endif
