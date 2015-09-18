#include "7za.h"
#include "7za_log.h"
#include <stdlib.h>


JNIEXPORT jint JNICALL Java_com_sina_sinavideo_coreplayer_splayer_SPlayer_initializeLibs(
							JNIEnv *env, 
							jobject thiz, 
							jstring libPath, 
							jstring destDir, 
							jstring prefix )
{
    LOG_D("%s: into.\n",__FUNCTION__);
	
	#define  ARGC 6 
	const char *test_args [ARGC+1] = {
		"7za",
		"e",
		"-r",
		0, //"-o/media",
		0, //"/media/libsplayer.7z",
		0, //"libneon.so",
		0
	};

	
	const char *tmpPath = env->GetStringUTFChars(libPath, NULL);
    if (tmpPath == NULL) {  // Out of memory
		LOG_E("%s: get libPath fail\n",__FUNCTION__);
        return -1;
    }
	
	const char *tmpDest = env->GetStringUTFChars(destDir, NULL);
    if (tmpDest == NULL) {  // Out of memory
		LOG_E("%s: get destDir fail\n",__FUNCTION__);
        return -1;
    }
	
	const char *tmpPrefix = env->GetStringUTFChars(prefix, NULL);
    if (tmpDest == NULL) {  // Out of memory
		LOG_E("%s: get prefix fail\n",__FUNCTION__);
        return -1;
    }
	
	LOG_D("%s: libPath=%s,destDir=%s,prefix=%s.\n",__FUNCTION__,tmpPath,tmpDest,tmpPrefix);
	
	char arg_out_path[1024];
	memset(arg_out_path,0,sizeof(arg_out_path));
	sprintf(arg_out_path,"-o%s",tmpDest);
	test_args[3] = arg_out_path;
	
	//char arg_src_file[1024];
	//memset(arg_src_file,0,sizeof(arg_src_file));
	//sprintf(arg_out_path,"%s",tmpPath);
	test_args[4] = tmpPath;
	
	char arg_extrat_file[100];
	memset(arg_extrat_file,0,sizeof(arg_extrat_file));
	sprintf(arg_extrat_file,"%s/*",tmpPrefix);
	test_args[5] = arg_extrat_file;
	
	jint ret = andro7za_main(ARGC, test_args);
	
	
	env->ReleaseStringUTFChars(libPath, tmpPath);
    tmpPath = NULL;
	env->ReleaseStringUTFChars(destDir, tmpDest);
    tmpDest = NULL;
	env->ReleaseStringUTFChars(prefix, tmpPrefix);
    tmpPrefix = NULL;
	
	LOG_D("%s: out. ret=%d\n",__FUNCTION__,ret);
    return ret;
}



jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env = NULL;
    jint result = -1;

	if(vm==NULL){
		__android_log_print(ANDROID_LOG_ERROR, "%s: load error, vm NULL",__FUNCTION__); 
		return result;
	}

    if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "%s: get env fail",__FUNCTION__);
        goto bail;
    }
   
    /* success -- return valid version number */
    result = JNI_VERSION_1_4;

bail:
    return result;
}