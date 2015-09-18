# Copyright (C) 2011, SNDA
# ndk application configuration for 7za
# Author: tangyaguang@snda.com
APP_ABI := armeabi-v7a x86 x86_64 arm64-v8a mips mips64

# Add stl port support, this setting is not automatically added
#APP_STL := gnustl_static

#APP_STL := stlport_shared
#APP_STL := stlport_static

#add by lyh
APP_CFLAGS += -Wno-error=format-security

APP_PLATFORM := android-9
