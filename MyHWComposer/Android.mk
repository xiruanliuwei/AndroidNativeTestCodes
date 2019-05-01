
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyHWComposer

LOCAL_SRC_FILES := MyHWComposer.cpp

LOCAL_C_INCLUDES := \
	hardware/libhardware/include \
	system/core/include

LOCAL_SHARED_LIBRARIES :=

LOCAL_LDLIBS := \
		-lhardware \
        -llog \
        -lutils

LOCAL_MODULE_PATH := $(LOCAL_PATH)

include $(BUILD_EXECUTABLE)
