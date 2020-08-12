//
// Created by louie fozard on 2020-08-10.
//

#include "../util.h"
#include "io_manxboy_js_value_JsPromise.h"

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsPromise_nativeDestructor(JNIEnv *env, jobject that, jobject runtime, jlong ptr) {

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *value = (v8::Global<v8::Value> *) ptr;

    value->Reset();

    delete value;
}