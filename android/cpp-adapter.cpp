#include <jni.h>
#include "react-native-xxhash.h"

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_xxhash_XxhashModule_nativeMultiply(JNIEnv *env, jclass type, jdouble a, jdouble b) {
    return xxhash::multiply(a, b);
}
