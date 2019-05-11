
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := my_buffer_queue

LOCAL_SRC_FILES :=	\
	MyBufferQueue.cpp

LOCAL_C_INCLUDES :=	\
	frameworks/native/libs/gui/include	\
	frameworks/native/libs/ui/include	\
	system/core/include

LOCAL_SHARED_LIBRARIES :=

LOCAL_LDLIBS :=	\
	-lgui		\
	-llog		\
	-lui		\
	-lutils

LOCAL_MODULE_PATH := $(LOCAL_PATH)

include $(BUILD_EXECUTABLE)
