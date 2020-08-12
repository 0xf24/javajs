//
// Created by louie fozard on 2020-08-09.
//

#include "../util.h"
#include "io_manxboy_js_value_JsObject.h"

JNIEXPORT jlong JNICALL Java_io_manxboy_js_value_JsObject_nativeConstructor(JNIEnv * env, jclass, jobject /*runtime*/ ctx_obj) {
    auto isolate = getRefIsolate(env, ctx_obj);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    auto *global_ref = new v8::Global<v8::Object>(isolate, v8::Object::New(isolate));

    return (jlong) global_ref;
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsObject_nativeDestructor(JNIEnv * env, jobject that, jobject runtime, jlong ptr) {

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *value = (v8::Global<v8::Value> *) ptr;

    value->Reset();

    delete value;
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsObject_get__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2(JNIEnv * env, jobject that, jobject ctx_obj, jstring key) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    return wrap(env, runtime, obj->Get(context, v8::Local<v8::Value>::Cast(javaStringToJs(env, isolate, key))));
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsObject_get__Lio_manxboy_js_value_JsContext_2Lio_manxboy_js_value_JsValue_2(JNIEnv * env, jobject that, jobject ctx_obj, jobject key) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    v8::Local<v8::Value> key_value = getRef(env, that)->Get(isolate);

    return wrap(env, runtime, obj->Get(context, key_value));
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsObject_get__Lio_manxboy_js_value_JsContext_2I(JNIEnv * env, jobject that, jobject ctx_obj, jint index) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    return wrap(env, runtime, obj->Get(context, index));
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsObject_set__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2Lio_manxboy_js_value_JsValue_2
        (JNIEnv * env, jobject that, jobject ctx_obj, jstring key, jobject value_obj) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    v8::Local<v8::Value> value = getRef(env, value_obj)->Get(isolate);

    //TODO: Error checking?
    obj->Set(context, v8::Local<v8::Value>::Cast(javaStringToJs(env, isolate, key)), value);
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsObject_set__Lio_manxboy_js_value_JsContext_2Lio_manxboy_js_value_JsValue_2Lio_manxboy_js_value_JsValue_2
        (JNIEnv * env, jobject that, jobject ctx_obj, jobject key_obj, jobject value_obj) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    v8::Local<v8::Value> value = getRef(env, value_obj)->Get(isolate);

    v8::Local<v8::Value> key = getRef(env, key_obj)->Get(isolate);

    //TODO: Error checking?
    obj->Set(context, key, value);
}

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsObject_set__Lio_manxboy_js_value_JsContext_2ILio_manxboy_js_value_JsValue_2
        (JNIEnv * env, jobject that, jobject ctx_obj, jint index, jobject value_obj) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    v8::Local<v8::Value> value = getRef(env, value_obj)->Get(isolate);

    obj->Set(context, index, value);
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsObject_delete__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2
        (JNIEnv * env, jobject that, jobject ctx_obj, jstring key) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    return obj->Delete(context, v8::Local<v8::Value>::Cast(javaStringToJs(env, isolate, key))).ToChecked();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsObject_delete__Lio_manxboy_js_value_JsContext_2Lio_manxboy_js_value_JsValue_2
        (JNIEnv * env, jobject that, jobject ctx_obj, jobject key_obj) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    v8::Local<v8::Value> key = getRef(env, key_obj)->Get(isolate);

    return obj->Delete(context, key).ToChecked();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsObject_delete__Lio_manxboy_js_value_JsContext_2I
        (JNIEnv * env, jobject that, jobject ctx_obj, jint index) {
    jobject runtime = env->GetObjectField(that, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Local<v8::Object> obj = v8::Local<v8::Object>::Cast(getRef(env, that)->Get(isolate));

    return obj->Delete(context, index).ToChecked();
}

//JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsObject_has__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2
//        (JNIEnv * env, jobject that, jobject ctx_obj, jstring) {
//
//}