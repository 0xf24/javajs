//
// Created by louie on 7/30/2020.
//

#include "util.h"

struct ClassTable classTable;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_8) != JNI_OK) {
        return JNI_ERR;
    }

    classTable.JsRuntime  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsRuntime" ));

    classTable.JsContext  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsContext" ));
    classTable.JsContextCtor = env->GetMethodID(classTable.JsContext, "<init>", "(J)V");

    classTable.JsValue    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsValue"   ));
    classTable.JsValueCtor = env->GetMethodID(classTable.JsValue, "<init>", "(J)V");

    classTable.JsArray    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsArray"   ));
    classTable.JsArrayCtor = env->GetMethodID(classTable.JsArray, "<init>", "(J)V");

    classTable.JsFunction = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsFunction"));
    classTable.JsFunctionCtor = env->GetMethodID(classTable.JsFunction, "<init>", "(J)V");

    classTable.JsMap      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsMap"     ));
    classTable.JsMapCtor = env->GetMethodID(classTable.JsMap, "<init>", "(J)V");

    classTable.JsObject   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsObject"  ));
    classTable.JsObjectCtor = env->GetMethodID(classTable.JsObject, "<init>", "(J)V");

    classTable.JsPromise  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsPromise" ));
    classTable.JsPromiseCtor = env->GetMethodID(classTable.JsPromise, "<init>", "(J)V");

    classTable.JsSet      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsSet"     ));
    classTable.JsSetCtor = env->GetMethodID(classTable.JsSet, "<init>", "(J)V");

    classTable.JsSymbol   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsSymbol"  ));
    classTable.JsSymbolCtor = env->GetMethodID(classTable.JsSymbol, "<init>", "(J)V");

    classTable.JsError    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsError"   ));
    classTable.JsErrorCtor = env->GetMethodID(classTable.JsError, "<init>", "(J)V");

    classTable.JsModule   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsModule"  ));
    classTable.JsModuleCtor = env->GetMethodID(classTable.JsModule, "<init>", "(J)V");

    classTable.JsScript   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsScript"  ));
    classTable.JsScriptCtor = env->GetMethodID(classTable.JsScript, "<init>", "(J)V");

}