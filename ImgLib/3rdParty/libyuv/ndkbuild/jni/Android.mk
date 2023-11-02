# This is the Android makefile for libyuv for NDK.
LOCAL_PATH:= $(call my-dir)
LIBYUV_PATH:= $(LOCAL_PATH)/../..
include $(CLEAR_VARS)
LOCAL_CPP_EXTENSION := .cc
LOCAL_SRC_FILES := \
    $(LIBYUV_PATH)/source/compare.cc           \
    $(LIBYUV_PATH)/source/compare_common.cc    \
    $(LIBYUV_PATH)/source/compare_gcc.cc       \
    $(LIBYUV_PATH)/source/compare_msa.cc       \
    $(LIBYUV_PATH)/source/compare_neon.cc      \
    $(LIBYUV_PATH)/source/compare_neon64.cc    \
    $(LIBYUV_PATH)/source/compare_win.cc       \
    $(LIBYUV_PATH)/source/convert.cc           \
    $(LIBYUV_PATH)/source/convert_argb.cc      \
    $(LIBYUV_PATH)/source/convert_from.cc      \
    $(LIBYUV_PATH)/source/convert_from_argb.cc \
    $(LIBYUV_PATH)/source/convert_to_argb.cc   \
    $(LIBYUV_PATH)/source/convert_to_i420.cc   \
    $(LIBYUV_PATH)/source/cpu_id.cc            \
    $(LIBYUV_PATH)/source/planar_functions.cc  \
    $(LIBYUV_PATH)/source/rotate.cc            \
    $(LIBYUV_PATH)/source/rotate_any.cc        \
    $(LIBYUV_PATH)/source/rotate_argb.cc       \
    $(LIBYUV_PATH)/source/rotate_common.cc     \
    $(LIBYUV_PATH)/source/rotate_gcc.cc        \
    $(LIBYUV_PATH)/source/rotate_msa.cc        \
    $(LIBYUV_PATH)/source/rotate_neon.cc       \
    $(LIBYUV_PATH)/source/rotate_neon64.cc     \
    $(LIBYUV_PATH)/source/rotate_win.cc        \
    $(LIBYUV_PATH)/source/row_any.cc           \
    $(LIBYUV_PATH)/source/row_common.cc        \
    $(LIBYUV_PATH)/source/row_gcc.cc           \
    $(LIBYUV_PATH)/source/row_msa.cc           \
    $(LIBYUV_PATH)/source/row_neon.cc          \
    $(LIBYUV_PATH)/source/row_neon64.cc        \
    $(LIBYUV_PATH)/source/row_win.cc           \
    $(LIBYUV_PATH)/source/scale.cc             \
    $(LIBYUV_PATH)/source/scale_any.cc         \
    $(LIBYUV_PATH)/source/scale_argb.cc        \
    $(LIBYUV_PATH)/source/scale_common.cc      \
    $(LIBYUV_PATH)/source/scale_gcc.cc         \
    $(LIBYUV_PATH)/source/scale_msa.cc         \
    $(LIBYUV_PATH)/source/scale_neon.cc        \
    $(LIBYUV_PATH)/source/scale_neon64.cc      \
    $(LIBYUV_PATH)/source/scale_rgb.cc         \
    $(LIBYUV_PATH)/source/scale_uv.cc          \
    $(LIBYUV_PATH)/source/scale_win.cc         \
    $(LIBYUV_PATH)/source/video_common.cc


#ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
#    LOCAL_CFLAGS += -DLIBYUV_NEON
#    LOCAL_SRC_FILES += \
#        $(LIBYUV_PATH)/source/compare_neon64.cc    \
#        $(LIBYUV_PATH)/source/rotate_neon64.cc     \
#        $(LIBYUV_PATH)/source/row_neon64.cc        \
#        $(LIBYUV_PATH)/source/scale_neon64.cc
#endif
#
#ifeq ($(TARGET_ARCH_ABI),$(filter $(TARGET_ARCH_ABI), x86 x86_64))
#    LOCAL_SRC_FILES += \
#        $(LIBYUV_PATH)/source/compare_gcc.cc       \
#        $(LIBYUV_PATH)/source/rotate_gcc.cc        \
#        $(LIBYUV_PATH)/source/row_gcc.cc           \
#        $(LIBYUV_PATH)/source/scale_gcc.cc
#endif

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
LOCAL_CFLAGS    += -mfloat-abi=softfp -mfpu=neon
LOCAL_CFLAGS    += -march=armv7-a -mtune=cortex-a8
else ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
LOCAL_CFLAGS    += -march=armv8-a -D__aarch64__
else ifeq ($(TARGET_ARCH_ABI),x86)
LOCAL_CFLAGS    += -D__X86__
else ifeq ($(TARGET_ARCH_ABI),x86_64)
LOCAL_CFLAGS    += -D__X86__
endif

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
common_CFLAGS := -Wall -fexceptions
LOCAL_CFLAGS += $(common_CFLAGS)
LOCAL_EXPORT_C_INCLUDES := $(LIBYUV_PATH)/include
LOCAL_C_INCLUDES += $(LIBYUV_PATH)/include
LOCAL_EXPORT_C_INCLUDE_DIRS := $(LIBYUV_PATH)/include

LOCAL_MODULE := yuv
LOCAL_MODULE_TAGS := optional

include $(BUILD_STATIC_LIBRARY)