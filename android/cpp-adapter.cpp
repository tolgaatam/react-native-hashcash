#include <jni.h>
#include "react-native-hashcash.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_com_hashcash_HashcashModule_nativeCalculateHashcash(JNIEnv *env, jclass type, jdouble k, jstring identifier) {
    const char *cstr = env->GetStringUTFChars(identifier, NULL);
    std::string str = std::string(cstr);
    std::string result = hashcash::calculateHashcash(k, str);

    env->ReleaseStringUTFChars(identifier, cstr);

    jstring result_jstring = env->NewStringUTF(result.c_str());
    return result_jstring;
}
