
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := MyComposerService

LOCAL_SRC_FILES := MyComposerService.cpp

LOCAL_C_INCLUDES := \
	frameworks/native/libs/binder/include \
	frameworks/native/libs/gui/include \
	frameworks/native/libs/ui/include \
	system/core/include

LOCAL_SHARED_LIBRARIES :=

LOCAL_LDLIBS := \
	-lbinder \
	-lgui \
	-llog \
	-lutils

LOCAL_MODULE_PATH := $(LOCAL_PATH)

include $(BUILD_EXECUTABLE)
