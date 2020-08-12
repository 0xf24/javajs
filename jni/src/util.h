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

#define START_V8_FUNC(isolate) \
    v8::Isolate::Scope isolate_scope(isolate);\
    v8::HandleScope scope(isolate)

#define START_V8_FUNC_CTX(isolate, global_context)\
    v8::Isolate::Scope isolate_scope(isolate);\
    v8::HandleScope scope(isolate);\
    v8::Local<v8::Context> context = global_context->Get(isolate);\
    v8::Context::Scope context_scope(context)

struct ClassTable {
    jclass V8Ref;
    jfieldID V8RefPtr;
    jfieldID V8RefRuntime;

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

    jclass JsException;
    jmethodID JsExceptionCtor;
};

extern struct ClassTable classTable;
extern std::unique_ptr<v8::Platform> platform;
extern v8::ArrayBuffer::Allocator* allocator;

v8::Isolate * getIsolate(JNIEnv *env, jobject runtime);

v8::Isolate * getRefIsolate(JNIEnv *env, jobject ref);

v8::Global<v8::Value> * getRef(JNIEnv *env, jobject ref);

v8::Global<v8::Context> * getContext(JNIEnv * env, jobject context);

jstring jsStringToJava(JNIEnv * env, v8::Isolate* isolate, v8::Local<v8::String> string);

v8::Local<v8::String> javaStringToJs(JNIEnv * env, v8::Isolate* isolate, jstring string);

//jobject wrap(JNIEnv * env, v8::Isolate* isolate, T value);

jobject wrap(JNIEnv * env, jobject runtime, v8::Local<v8::Value> value);

jobject wrap(JNIEnv * env, jobject runtime, v8::MaybeLocal<v8::Value> value);


#endif //JAVAJS_JNI_UTIL_H