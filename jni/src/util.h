//
// Created by louie on 7/30/2020.
//

#ifndef JAVAJS_JNI_UTIL_H
#define JAVAJS_JNI_UTIL_H

#include <jni.h>

struct ClassTable {
    jclass V8Ref;
    jfieldID V8RefPtr;

    jclass JsRuntime;

    jclass JsContext;
    jmethodID JsContextCtor;

    jclass JsValue;
    jmethodID JsValueCtor;

    jclass JsArray;
    jmethodID JsArrayCtor;

    jclass JsFunction;
    jmethodID JsFunctionCtor;

    jclass JsMap;
    jmethodID JsMapCtor;

    jclass JsObject;
    jmethodID JsObjectCtor;

    jclass JsPromise;
    jmethodID JsPromiseCtor;

    jclass JsSet;
    jmethodID JsSetCtor;

    jclass JsSymbol;
    jmethodID JsSymbolCtor;

    jclass JsError;
    jmethodID JsErrorCtor;

    jclass JsModule;
    jmethodID JsModuleCtor;

    jclass JsScript;
    jmethodID JsScriptCtor;
};

extern struct ClassTable classTable;

#endif //JAVAJS_JNI_UTIL_H