//
// Created by louie on 7/30/2020.
//

#ifndef JAVAJS_JNI_UTIL_H
#define JAVAJS_JNI_UTIL_H

#include <jni.h>
#include <cstdio>
#include <stdlib.h>
#include <libplatform/libplatform.h>
#include <v8.h>

struct ClassTable {
    jclass V8Ref;
    jfieldID V8RefPtr;
    jfieldID V8RtPtr;

    jclass JsRuntime;
    jfieldID JsRuntimePtr;

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
extern std::unique_ptr<v8::Platform> platform;
extern v8::ArrayBuffer::Allocator* allocator;

#endif //JAVAJS_JNI_UTIL_H