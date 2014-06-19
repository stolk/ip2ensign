LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := ip2ensign
LOCAL_SRC_FILES := src/ip2ensign.c

#LOCAL_C_INCLUDES := 

LOCAL_CFLAGS += -std=c99

include $(BUILD_STATIC_LIBRARY)

