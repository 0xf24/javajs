//
// Created by louie on 7/30/2020.
//

#include "util.h"

struct ClassTable classTable;
std::unique_ptr<v8::Platform> platform;
v8::ArrayBuffer::Allocator* allocator;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_8) != JNI_OK) {
        return JNI_ERR;
    }


    printf("loading v8ref\n");
    classTable.V8Ref = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/impl/V8Ref"));
    classTable.V8RefPtr = env->GetFieldID(classTable.V8Ref, "ptr", "J");
    classTable.V8RtPtr = env->GetFieldID(classTable.V8Ref, "rt_ptr", "J");

    printf("loading JsRuntime\n");
    classTable.JsRuntime  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsRuntime" ));
    classTable.JsRuntimePtr = env->GetFieldID(classTable.JsRuntime, "ptr", "J");

    printf("loading JsContext\n");
    classTable.JsContext  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsContext" ));
    classTable.JsContextCtor = env->GetMethodID(classTable.JsContext, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    printf("loading JsValue\n");
    classTable.JsValue    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsValue"   ));
    classTable.JsValueCtor = env->GetMethodID(classTable.JsValue, "<init>", "(JJ)V");

    printf("loading JsArray\n");
    classTable.JsArray    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsArray"   ));
    classTable.JsArrayCtor = env->GetMethodID(classTable.JsArray, "<init>", "(JJ)V");

    printf("loading JsFunction\n");
    classTable.JsFunction = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsFunction"));
    classTable.JsFunctionCtor = env->GetMethodID(classTable.JsFunction, "<init>", "(JJ)V");

    printf("loading JsMap\n");
    classTable.JsMap      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsMap"     ));
    classTable.JsMapCtor = env->GetMethodID(classTable.JsMap, "<init>", "(JJ)V");

    printf("loading JsObject\n");
    classTable.JsObject   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsObject"  ));
    classTable.JsObjectCtor = env->GetMethodID(classTable.JsObject, "<init>", "(JJ)V");

    printf("loading JsPromise\n");
    classTable.JsPromise  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsPromise" ));
    classTable.JsPromiseCtor = env->GetMethodID(classTable.JsPromise, "<init>", "(JJ)V");

    printf("loading JsSet\n");
    classTable.JsSet      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsSet"     ));
    classTable.JsSetCtor = env->GetMethodID(classTable.JsSet, "<init>", "(JJ)V");

    printf("loading JsSymbol\n");
    classTable.JsSymbol   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsSymbol"  ));
    classTable.JsSymbolCtor = env->GetMethodID(classTable.JsSymbol, "<init>", "(JJ)V");

    printf("loading JsError\n");
    classTable.JsError    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsError"   ));
    classTable.JsErrorCtor = env->GetMethodID(classTable.JsError, "<init>", "(JJ)V");

    printf("loading JsModule\n");
    classTable.JsModule   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/script/JsModule"  ));
    classTable.JsModuleCtor = env->GetMethodID(classTable.JsModule, "<init>", "(JJ)V");

    printf("loading JsScript\n");
    classTable.JsScript   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/script/JsScript"  ));
    classTable.JsScriptCtor = env->GetMethodID(classTable.JsScript, "<init>", "(JJ)V");


    platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();

    allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();

    return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_8) == JNI_OK) {
        env->DeleteGlobalRef(classTable.V8Ref);
        env->DeleteGlobalRef(classTable.JsArray);
        env->DeleteGlobalRef(classTable.JsError);
        env->DeleteGlobalRef(classTable.JsContext);
        env->DeleteGlobalRef(classTable.JsFunction);
        env->DeleteGlobalRef(classTable.JsMap);
        env->DeleteGlobalRef(classTable.JsModule);
        env->DeleteGlobalRef(classTable.JsObject);
        env->DeleteGlobalRef(classTable.JsPromise);
        env->DeleteGlobalRef(classTable.JsScript);
        env->DeleteGlobalRef(classTable.JsRuntime);
        env->DeleteGlobalRef(classTable.JsSet);
        env->DeleteGlobalRef(classTable.JsSymbol);
        env->DeleteGlobalRef(classTable.JsValue);
    }

    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();
    delete allocator;
}