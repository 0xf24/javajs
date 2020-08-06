//
// Created by louie fozard on 2020-08-04.
//

#include "util.h"
#include "io_manxboy_js_value_JsContext.h"

JNIEXPORT jlong JNICALL Java_io_manxboy_js_value_JsContext_nativeConstructor(JNIEnv * env, jclass, jlong rt_ptr) {
    auto isolate = (v8::Isolate*) rt_ptr;

    isolate->Enter();

    //create new dynamically allocated context
    auto *context = new v8::Global<v8::Context>;

    context->Reset(isolate, v8::Context::New(isolate));

    isolate->Exit();

    //return the pointer wrapped as a long
    return (jlong) context;
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsContext_nativeDestructor(JNIEnv * env, jobject that, jlong rt_ptr, jlong ptr) {
    auto isolate = (v8::Isolate*) rt_ptr;

    auto *context = (v8::Global<v8::Context> *) ptr;

    context->Reset();

    delete context;
}