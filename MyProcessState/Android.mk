
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyProcessState

LOCAL_SRC_FILES := MyProcessState.cpp

LOCAL_C_INCLUDES := \
	frameworks/native/include \
	system/core/include \
	system/core/libutils/include
	


LOCAL_SHARED_LIBRARIES :=

LOCAL_LDLIBS := \
	-lbinder \
	-llog \
	-lutils

LOCAL_MODULE_PATH := $(LOCAL_PATH)

include $(BUILD_EXECUTABLE)

