//
// Created by louie on 7/31/2020.
//

#include "../util.h"
#include "io_manxboy_js_value_JsRuntime.h"

JNIEXPORT jlong JNICALL Java_io_manxboy_js_value_JsRuntime_nativeConstructor (JNIEnv *env, jclass) {
    v8::Isolate::CreateParams params;
    params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();

    v8::Isolate *isolate = v8::Isolate::New(params);
    return (jlong) isolate;
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsRuntime_nativeDestructor (JNIEnv * env, jobject that, jlong ptr) {
    auto *isolate = (v8::Isolate*) ptr;

    isolate->Dispose();

    //delete isolate;
}