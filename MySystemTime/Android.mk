
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MySystemTime

LOCAL_SRC_FILES := MySystemTime.cpp

LOCAL_C_INCLUDES := \
	system/core/include

LOCAL_SHARED_LIBRARIES :=

LOCAL_LDLIBS := \
        -llog \
        -lutils

LOCAL_MODULE_PATH := $(LOCAL_PATH)

include $(BUILD_EXECUTABLE)
