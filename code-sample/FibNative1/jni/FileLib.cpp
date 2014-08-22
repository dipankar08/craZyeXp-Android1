/* DO NOT EDIT THIS FILE - it is machine generated
 *  adb -d shell cat /sdcard/hello.txt
 *  */
#include "FileLib.h"
#include<android/log.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <fcntl.h>
using namespace std;

JNIEXPORT jbyteArray JNICALL Java_com_example_fibnative_FileLib_getFileData (JNIEnv * env, jclass jc)
{

	__android_log_print(ANDROID_LOG_DEBUG, "DD_FILELIB","read STARTED..");
	FILE *fl = fopen("/sdcard/data1.txt", "r");
	fseek(fl, 0, SEEK_END);
	long len = ftell(fl);
	char *ret = (char *)malloc(len);
	fseek(fl, 0, SEEK_SET);
	fread(ret, 1, len, fl);
	fclose(fl);
	__android_log_print(ANDROID_LOG_DEBUG, "DD_FILELIB","read %s",ret);
	__android_log_print(ANDROID_LOG_DEBUG, "DD_FILELIB","read done(%ld)",len);

	jbyteArray jdest = env->NewByteArray(len);
	if(jdest != NULL){
	 env->SetByteArrayRegion(jdest,0,len,(jbyte *)ret);
	   return(jdest);
	}
	return(jdest);
}

/*
 * Class:     com_example_fibnative_FileLib
 * Method:    setFileData
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_com_example_fibnative_FileLib_setFileData(JNIEnv * env, jclass cls , jbyteArray jpSeed)
{

	__android_log_print(ANDROID_LOG_DEBUG, "DD_FILELIB","i am in abc");

    const jbyte* buf =  env->GetByteArrayElements(jpSeed,NULL);
    const jlong buflngth = env->GetArrayLength(jpSeed);
//write
    FILE* file = fopen("/sdcard/data1.txt","wb");
    if (file != NULL)
    {
        //fputs("HELLO WORLD!\n", file);
    	//fputs((const char *)buf,file);
    	fwrite((const char *)buf,1,buflngth,file);
        fflush(file);
        fclose(file);
    }
	__android_log_print(ANDROID_LOG_DEBUG, "DD_FILELIB","write done(%lld)",buflngth);


}
