//
// Created by louie fozard on 2020-08-07.
//

#include "../util.h"

#include "io_manxboy_js_value_JsValue.h"

JNIEXPORT void JNICALL Java_io_manxboy_js_value_JsValue_nativeDestructor(JNIEnv * env, jobject that, jobject runtime, jlong ptr) {
    //auto isolate = (v8::Isolate*) rt_ptr;

    auto *value = (v8::Global<v8::Value> *) ptr;

    value->Reset();

    delete value;
}


JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsValue_from__Lio_manxboy_js_value_JsRuntime_2I(JNIEnv * env, jclass, jobject runtime, jint value) {
    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

//    v8::Isolate::Scope isolate_scope(isolate);
//
//    v8::HandleScope scope(isolate);

    auto *global_ref = new v8::Global<v8::Integer>(isolate, v8::Integer::New(isolate, (int32_t) value));

    return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsValue_from__Lio_manxboy_js_value_JsRuntime_2J(JNIEnv * env, jclass, jobject runtime, jlong value) {
    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *global_ref = new v8::Global<v8::BigInt>(isolate, v8::BigInt::New(isolate, value));

    return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsValue_from__Lio_manxboy_js_value_JsRuntime_2D(JNIEnv * env, jclass, jobject runtime, jdouble value) {
    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *global_ref = new v8::Global<v8::Number>(isolate, v8::Number::New(isolate, value));

    return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsValue_from__Lio_manxboy_js_value_JsRuntime_2Z(JNIEnv * env, jclass, jobject runtime, jboolean value) {
    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *global_ref = new v8::Global<v8::Boolean>(isolate, v8::Boolean::New(isolate, value));

    return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_value_JsValue_from__Lio_manxboy_js_value_JsRuntime_2Ljava_lang_String_2(JNIEnv * env, jclass, jobject runtime, jstring value) {
    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    const char* raw_string = env->GetStringUTFChars(value, nullptr);

    int length = env->GetStringUTFLength(value);

    //TODO: add checking here
    auto *global_ref = new v8::Global<v8::String>(isolate, v8::String::NewFromUtf8(isolate, raw_string, v8::NewStringType::kNormal, length).ToLocalChecked());

    env->ReleaseStringUTFChars(value, raw_string);

    return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);
}

JNIEXPORT jdouble JNICALL Java_io_manxboy_js_value_JsValue_toDouble(JNIEnv * env, jobject that, jobject ctx_obj) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    auto global_context_ref = getContext(env, ctx_obj);

    auto context = global_context_ref->Get(isolate);

    v8::Local<v8::Value> value = global_ref->Get(isolate);

    auto number = value->NumberValue(context);

    //TODO: add error checking

    return number.ToChecked();
}

JNIEXPORT jint JNICALL Java_io_manxboy_js_value_JsValue_toInt(JNIEnv * env, jobject that, jobject ctx_obj) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    auto global_context_ref = getContext(env, ctx_obj);

    auto context = global_context_ref->Get(isolate);

    //TODO: add error checking

    return global_ref->Get(isolate)->Int32Value(context).ToChecked();
}

JNIEXPORT jlong JNICALL Java_io_manxboy_js_value_JsValue_toLong(JNIEnv * env, jobject that, jobject ctx_obj) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    auto global_context_ref = getContext(env, ctx_obj);

    auto context = global_context_ref->Get(isolate);

    //TODO: add error checking

    return global_ref->Get(isolate)->IntegerValue(context).ToChecked();
}

JNIEXPORT jstring JNICALL Java_io_manxboy_js_value_JsValue_toString__(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    v8::String::Value val16(isolate, global_ref->Get(isolate));

    int length = val16.length();

    if (length > 0) {
        return env->NewString(*val16, val16.length());
    }

    return nullptr;
}

JNIEXPORT jstring JNICALL Java_io_manxboy_js_value_JsValue_toString__Lio_manxboy_js_value_JsContext_2(JNIEnv * env, jobject that, jobject ctx_obj) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    auto global_context_ref = getContext(env, ctx_obj);

    auto context = global_context_ref->Get(isolate);


    v8::Local<v8::String> string;

    if (global_ref->Get(isolate)->ToString(context).ToLocal(&string)) {

        return jsStringToJava(env, isolate, string);

    }

    return nullptr;
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_toBoolean(JNIEnv * env, jobject that, jobject ctx_obj) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    return global_ref->Get(isolate)->BooleanValue(isolate);
}

JNIEXPORT jstring JNICALL Java_io_manxboy_js_value_JsValue_toDetailString(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto global_ref = getRef(env, that);

    v8::String::Value val16(isolate, global_ref->Get(isolate));

    int length = val16.length();

    if (length > 0) {
        return env->NewString(*val16, val16.length());
    }

    return nullptr;
};

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_equals(JNIEnv * env, jobject a, jobject b) {
    auto isolate = getRefIsolate(env, a);

    START_V8_FUNC(isolate);

    auto global_a = getRef(env, a);
    auto global_b = getRef(env, b);

    return global_a->Get(isolate)->StrictEquals(global_b->Get(isolate));
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_looseEquals(JNIEnv * env, jobject a, jobject ctx_obj, jobject b) {
    auto isolate = getRefIsolate(env, a);

    START_V8_FUNC(isolate);

    auto global_a = getRef(env, a);
    auto global_b = getRef(env, b);

    auto context = getContext(env, ctx_obj)->Get(isolate);

    v8::Maybe<bool> result = global_a->Get(isolate)->Equals(context, global_b->Get(isolate));

    if (result.IsJust()) {
        return result.ToChecked();
    } else {
        //TODO: error check here
        return false;
    }
}

JNIEXPORT jstring JNICALL Java_io_manxboy_js_value_JsValue_typeOf(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    auto ref = getRef(env, that)->Get(isolate);

    auto string = ref->TypeOf(isolate);

    return jsStringToJava(env, isolate, string);
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isNull(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsNull();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isUndefined(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsUndefined();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isString(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsString();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isNumber(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsNumber();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isTrue(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsTrue();
}

JNIEXPORT jboolean JNICALL Java_io_manxboy_js_value_JsValue_isFalse(JNIEnv * env, jobject that) {
    auto isolate = getRefIsolate(env, that);

    START_V8_FUNC(isolate);

    return getRef(env, that)->Get(isolate)->IsTrue();
}