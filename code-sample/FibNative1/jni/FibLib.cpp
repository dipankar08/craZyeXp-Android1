/* DO NOT EDIT THIS FILE - it is machine generated */
#include<jni.h>
#include<android/log.h>

namespace com_example_fibnative{

	static jlong fib(jlong n){
		return n<=0?0:n==1?1: fib(n-1)+fib(n-2);
	}

	static jlong  fibNR(JNIEnv *env, jclass cls, jlong n){
		__android_log_print(ANDROID_LOG_DEBUG, "DD_CPP","FibNR(%lld)",n);
		return fib( n);
	}

	static jlong fibNI(JNIEnv *env, jclass cl, jlong n){
		__android_log_print(ANDROID_LOG_DEBUG, "DD_CPP","FibNI(%lld)",n);
		jlong prev = -1;
		jlong res = 1;
		jlong i =0;
		jlong sum =0;
		for( i=0;i<= n;i++){
			sum = res+ prev;
			prev = res;
			res = sum;
		}
		return res;
	}
	static JNINativeMethod method_table[]={
			{"fibNR", "(J)J", (void *)fibNR},
			{"fibNI", "(J)J", (void *)fibNI}
	};
}

using namespace com_example_fibnative;

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }
    jclass cls = env->FindClass("com/example/fibnative/FibLib");
    if(cls){
    	//env->RegisterNatives(cls,method_table,sizeof(method_table/sizeof(method_table[0])));
    	env->RegisterNatives(cls,com_example_fibnative::method_table,2);
    	env->DeleteLocalRef(cls);
    	return JNI_VERSION_1_6;
    }
    else{
    	return -1;
    }
}


