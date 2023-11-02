# This is the Android makefile for libyuv for NDK.
LOCAL_PATH:= $(call my-dir)

IMGLIB_PAYH:=$(LOCAL_PATH)/../..

include $(IMGLIB_PAYH)/3rdParty/libyuv/ndkbuild/jni/Android.mk

include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(IMGLIB_PAYH)/src/Image.cpp \
				   $(IMGLIB_PAYH)/src/ImageUtils.cpp \
				   $(IMGLIB_PAYH)/src/utils.cpp


common_CFLAGS := -Wall -fexceptions

LOCAL_CFLAGS += $(common_CFLAGS)

LOCAL_C_INCLUDES += $(IMGLIB_PAYH)/include

LOCAL_MODULE := ImgLib
#LOCAL_MODULE_TAGS := optional
#LOCAL_LDLIBS += -llog
LOCAL_STATIC_LIBRARIES := yuv
#LOCAL_SHARED_LIBRARIES := libjpeg

include $(BUILD_STATIC_LIBRARY)
