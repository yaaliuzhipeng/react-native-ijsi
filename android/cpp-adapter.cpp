#include <jni.h>
#include <android/log.h>
#include "logger/react_native_log.h"
#include "react-native-ijsi.h"

#define TAG "JNI-cpp-adapter"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)

using namespace std;

void nativeInstall(JNIEnv *jsienv, jobject module,jlong jenv) {
    LOGD("this is native install method");
    auto rt = reinterpret_cast<Runtime *>(jenv);
    ijsi::install(*rt);
}

/**
 *  public native void nativeInstall(long jsi);
 */
JNINativeMethod methodTables[] = {
        {"nativeInstall","(J)V",(void *)nativeInstall}
};

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env = nullptr;
    if(vm->GetEnv((void **) &env,JNI_VERSION_1_6) != JNI_OK){
        return -1;
    }
    jclass jcls;
    jcls = env->FindClass("com/reactnativeijsi/IjsiModule");
    if(jcls == nullptr) return -1;
    if(env->RegisterNatives(jcls,methodTables,sizeof(methodTables)/sizeof(methodTables[0])) < 0){
        return -1;
    }
    env->DeleteLocalRef(jcls);
    return JNI_VERSION_1_6;
}
