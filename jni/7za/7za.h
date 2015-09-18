// Copyright (C) 2011, SNDA
// 
// JNI interface header
// 
// @author: tangyaguang@snda.com
// 
// @date: 2011-08-14
#include <jni.h>

#ifndef _7ZA_H_
#define _7ZA_H_

extern int andro7za_main(int numArgs, const char *argv[]);

#ifdef __cplusplus
extern "C"{
#endif
    
JNIEXPORT jint JNICALL Java_com_sina_sinavideo_coreplayer_splayer_SPlayer_initializeLibs(
							JNIEnv *env, 
							jobject thiz, 
							jstring libPath, 
							jstring destDir, 
							jstring prefix );
							
#ifdef __cplusplus
}
#endif

#endif  // _7ZA_H_
