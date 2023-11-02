# This is the Android makefile for libyuv for NDK.
LOCAL_PATH:= $(call my-dir)
TEST_PATH:=$(LOCAL_PATH)/../..
include $(TEST_PATH)/../ImgLib/ndkbuild/jni/Android.mk

include $(CLEAR_VARS)

LOCAL_MODULE := Test
LOCAL_SRC_FILES := $(TEST_PATH)/main.cpp

common_CFLAGS :=
#common_CFLAGS := -Wall -fexceptions

LOCAL_CFLAGS += $(common_CFLAGS)

LOCAL_C_INCLUDES :=$(TEST_PATH)/../ImgLib/include
LOCAL_C_INCLUDES +=$(TEST_PATH)/../ImgLib/3rdParty/libyuv/include


#LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := ImgLib

include $(BUILD_EXECUTABLE)
