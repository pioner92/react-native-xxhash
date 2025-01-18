#include <jni.h>
#include "react-native-xxhash.h"
#include "jsi/jsi.h"
#include <android/log.h>
#include <fbjni/fbjni.h>
#include <fbjni/detail/Registration.h>
#include <typeinfo>

//XXHashBridge


using namespace facebook;

struct XXHashBridge : jni::JavaClass<XXHashBridge> {
public:
    static constexpr auto kJavaDescriptor = "Lcom/xxhash/XxhashModule;";

    static void registerNatives() {
        javaClassStatic()->registerNatives({
                                                   makeNativeMethod("nativeInstall", XXHashBridge::nativeInstall)
                                           });
    }
private:
    static void nativeInstall(
            jni::alias_ref<jni::JObject> thiz,
            jlong jsiRuntimePointer
    ) {

        // Реализация
        auto jsiRuntime = reinterpret_cast<jsi::Runtime*>(jsiRuntimePointer);
        // Установите JSI
        xxhash::install(jsiRuntime);
    }
};

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *) {
    return jni::initialize(vm, [] { XXHashBridge::registerNatives(); });
}
