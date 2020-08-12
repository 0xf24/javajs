//
// Created by louie fozard on 2020-08-10.
//

#include "../util.h"
#include "io_manxboy_js_script_JsScript.h"

JNIEXPORT void JNICALL Java_io_manxboy_js_script_JsScript_nativeDestructor(JNIEnv *env, jobject that, jobject runtime, jlong ptr) {

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC(isolate);

    auto *value = (v8::Global<v8::Value> *) ptr;

    value->Reset();

    delete value;
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_script_JsScript_compile__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2
        (JNIEnv * env, jclass, jobject ctx_obj, jstring jsource) {
    auto runtime = env->GetObjectField(ctx_obj, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    auto source = javaStringToJs(env, isolate, jsource);

    v8::TryCatch tryCatch(isolate);

    auto maybeScript = v8::Script::Compile(context, source);

    if (tryCatch.HasCaught()) {
        auto error = tryCatch.Exception();

        jobject errorObject = wrap(env, runtime, v8::Local<v8::Value>::Cast(error));

        jstring message = jsStringToJava(env, isolate, tryCatch.Message()->Get());

        jobject exception = env->NewObject(classTable.JsException, classTable.JsExceptionCtor, message, errorObject);

        env->Throw((jthrowable) exception);

        tryCatch.Reset();

        return nullptr;
    }

    auto script = * maybeScript.ToLocalChecked();

    return env->NewObject(classTable.JsScript, classTable.JsScriptCtor, runtime, script);

    //auto *global_ref = new v8::Global<v8::Object>(isolate, v8::Object::New(isolate));

    //return (jlong) global_ref;
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_script_JsScript_compile__Lio_manxboy_js_value_JsContext_2Ljava_lang_String_2Lio_manxboy_js_ScriptOrigin_2
        (JNIEnv * env, jclass, jobject ctx_obj, jstring jsource, jobject origin) {
    auto runtime = env->GetObjectField(ctx_obj, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    auto source = javaStringToJs(env, isolate, jsource);

    v8::TryCatch tryCatch(isolate);

    auto maybeScript = v8::Script::Compile(context, source);

    if (tryCatch.HasCaught()) {
        auto error = tryCatch.Exception();

        jobject errorObject = wrap(env, runtime, v8::Local<v8::Value>::Cast(error));

        jstring message = jsStringToJava(env, isolate, tryCatch.Message()->Get());

        jobject exception = env->NewObject(classTable.JsException, classTable.JsExceptionCtor, message, errorObject);

        env->Throw((jthrowable) exception);

        tryCatch.Reset();

        return nullptr;
    }

    auto script = * maybeScript.ToLocalChecked();

    return env->NewObject(classTable.JsScript, classTable.JsScriptCtor, runtime, script);
}

JNIEXPORT jobject JNICALL Java_io_manxboy_js_script_JsScript_run(JNIEnv * env, jobject that, jobject ctx_obj) {

    auto runtime = env->GetObjectField(ctx_obj, classTable.V8RefRuntime);

    auto isolate = getIsolate(env, runtime);

    START_V8_FUNC_CTX(isolate, getContext(env, ctx_obj));

    v8::Script * script = (v8::Script *) env->GetLongField(that, classTable.V8RefPtr);

    v8::TryCatch tryCatch(isolate);

    v8::MaybeLocal<v8::Value> result = script->Run(context);

    if (tryCatch.HasCaught()) {

        auto error = tryCatch.Exception();

        jobject errorObject = wrap(env, runtime, v8::Local<v8::Value>::Cast(error));

        jstring message = jsStringToJava(env, isolate, tryCatch.Message()->Get());

        jobject exception = env->NewObject(classTable.JsException, classTable.JsExceptionCtor, message, errorObject);

        env->Throw((jthrowable) exception);

        tryCatch.Reset();

        return nullptr;
    }

    return wrap(env, runtime, result.ToLocalChecked());
}