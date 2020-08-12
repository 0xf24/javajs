//
// Created by louie on 7/30/2020.
//

#include "util.h"

struct ClassTable classTable;
std::unique_ptr<v8::Platform> platform;
v8::ArrayBuffer::Allocator* allocator;


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_8) != JNI_OK) {
        return JNI_ERR;
    }


    //printf("loading v8ref\n");
    classTable.V8Ref = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/impl/V8Ref"));
    classTable.V8RefPtr = env->GetFieldID(classTable.V8Ref, "ptr", "J");
    classTable.V8RefRuntime = env->GetFieldID(classTable.V8Ref, "runtime", "Lio/manxboy/js/value/JsRuntime;");

    //printf("loading JsRuntime\n");
    classTable.JsRuntime  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsRuntime" ));
    classTable.JsRuntimePtr = env->GetFieldID(classTable.JsRuntime, "ptr", "J");

    //printf("loading JsContext\n");
    classTable.JsContext  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsContext" ));
    classTable.JsContextCtor = env->GetMethodID(classTable.JsContext, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsValue\n");
    classTable.JsValue    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsValue"   ));
    classTable.JsValueCtor = env->GetMethodID(classTable.JsValue, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsArray\n");
    classTable.JsArray    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsArray"   ));
    classTable.JsArrayCtor = env->GetMethodID(classTable.JsArray, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsFunction\n");
    classTable.JsFunction = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsFunction"));
    classTable.JsFunctionCtor = env->GetMethodID(classTable.JsFunction, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsMap\n");
    classTable.JsMap      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsMap"     ));
    classTable.JsMapCtor = env->GetMethodID(classTable.JsMap, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsObject\n");
    classTable.JsObject   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsObject"  ));
    classTable.JsObjectCtor = env->GetMethodID(classTable.JsObject, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsPromise\n");
    classTable.JsPromise  = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsPromise" ));
    classTable.JsPromiseCtor = env->GetMethodID(classTable.JsPromise, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsSet\n");
    classTable.JsSet      = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsSet"     ));
    classTable.JsSetCtor = env->GetMethodID(classTable.JsSet, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsSymbol\n");
    classTable.JsSymbol   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsSymbol"  ));
    classTable.JsSymbolCtor = env->GetMethodID(classTable.JsSymbol, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsError\n");
    classTable.JsError    = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/value/JsError"   ));
    classTable.JsErrorCtor = env->GetMethodID(classTable.JsError, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsModule\n");
    classTable.JsModule   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/script/JsModule"  ));
    classTable.JsModuleCtor = env->GetMethodID(classTable.JsModule, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsScript\n");
    classTable.JsScript   = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/script/JsScript"  ));
    classTable.JsScriptCtor = env->GetMethodID(classTable.JsScript, "<init>", "(Lio/manxboy/js/value/JsRuntime;J)V");

    //printf("loading JsException\n");
    classTable.JsException = (jclass) env->NewGlobalRef(env->FindClass("io/manxboy/js/JsException"));
    classTable.JsExceptionCtor = env->GetMethodID(classTable.JsException, "<init>", "(Ljava/lang/String;Lio/manxboy/js/value/JsError;)V");

    platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();

    allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();

    return JNI_VERSION_1_8;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM *vm, void *reserved) {
    JNIEnv * env;
    if (vm->GetEnv((void**) &env, JNI_VERSION_1_8) == JNI_OK) {
        env->DeleteGlobalRef(classTable.V8Ref);
        env->DeleteGlobalRef(classTable.JsArray);
        env->DeleteGlobalRef(classTable.JsError);
        env->DeleteGlobalRef(classTable.JsContext);
        env->DeleteGlobalRef(classTable.JsFunction);
        env->DeleteGlobalRef(classTable.JsMap);
        env->DeleteGlobalRef(classTable.JsModule);
        env->DeleteGlobalRef(classTable.JsObject);
        env->DeleteGlobalRef(classTable.JsPromise);
        env->DeleteGlobalRef(classTable.JsScript);
        env->DeleteGlobalRef(classTable.JsRuntime);
        env->DeleteGlobalRef(classTable.JsSet);
        env->DeleteGlobalRef(classTable.JsSymbol);
        env->DeleteGlobalRef(classTable.JsValue);
    }

    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();
    delete allocator;
}

v8::Isolate * getIsolate(JNIEnv *env, jobject runtime) {
    return (v8::Isolate *) env->GetLongField(runtime, classTable.JsRuntimePtr);
}

v8::Isolate * getRefIsolate(JNIEnv *env, jobject ref) {
    jobject runtime = env->GetObjectField(ref, classTable.V8RefRuntime);

    return (v8::Isolate *) env->GetLongField(runtime, classTable.JsRuntimePtr);
}

v8::Global<v8::Value> * getRef(JNIEnv *env, jobject ref) {
    return (v8::Global<v8::Value> *) env->GetLongField(ref, classTable.V8RefPtr);
}

v8::Global<v8::Context> * getContext(JNIEnv * env, jobject context) {
    return (v8::Global<v8::Context> *) env->GetLongField(context, classTable.V8RefPtr);
}

jstring jsStringToJava(JNIEnv * env, v8::Isolate* isolate, v8::Local<v8::String> string) {
    int length = string->Length();

    auto buffer = new uint16_t[length];

    string->Write(isolate, buffer, 0, -1, v8::String::WriteOptions::NO_NULL_TERMINATION);

    jstring result = env->NewString(buffer, length);

    delete[] buffer;

    return result;
}

v8::Local<v8::String> javaStringToJs(JNIEnv * env, v8::Isolate* isolate, jstring string) {
    v8::Isolate::Scope isolate_scope(isolate);

    v8::EscapableHandleScope scope(isolate);

    int length = env->GetStringLength(string);

    const uint16_t * raw = env->GetStringChars(string, nullptr);

    v8::MaybeLocal<v8::String> result = v8::String::NewFromTwoByte(isolate, raw, v8::NewStringType::kNormal, length);

    env->ReleaseStringChars(string, raw);

    if (result.IsEmpty()) {
        return v8::Local<v8::String>::Cast(scope.Escape(v8::Undefined(isolate)));
    }

    return scope.Escape(result.ToLocalChecked());
}

jobject wrap(JNIEnv * env, jobject runtime, v8::MaybeLocal<v8::Value> value) {
    if (value.IsEmpty()) {
        return nullptr;
    } else {
        return wrap(env, runtime, value.ToLocalChecked());
    }
}

jobject wrap(JNIEnv * env, jobject runtime, v8::Local<v8::Value> value) {

    v8::Isolate * isolate = getIsolate(env, runtime);

    v8::Isolate::Scope isolate_scope(isolate);

    v8::HandleScope scope(isolate);

    jlong global_ref = (jlong) new v8::Global<v8::Value>(isolate, value);

    //return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, (jlong) global_ref);

    if (value->IsNumber() || value ->IsBoolean() || value ->IsString() || value->IsUndefined() || value->IsNull()) {
        return env->NewObject(classTable.JsValue, classTable.JsValueCtor, runtime, global_ref);
    }

    if (value->IsMap()) {
        return env->NewObject(classTable.JsMap, classTable.JsMapCtor, runtime, global_ref);
    }

    if (value->IsSet()) {
        return env->NewObject(classTable.JsSet, classTable.JsSetCtor, runtime, global_ref);
    }

//    if (value->IsNativeError()) {
//        return env->NewObject(classTable.JsError, classTable.JsErrorCtor, runtime, global_ref);
//    }

    if (value->IsSymbol()) {
        return env->NewObject(classTable.JsSymbol, classTable.JsSymbolCtor, runtime, global_ref);
    }

    if (value->IsPromise()) {
        return env->NewObject(classTable.JsPromise, classTable.JsPromiseCtor, runtime, global_ref);
    }

    if (value->IsFunction()) {
        return env->NewObject(classTable.JsFunction, classTable.JsFunctionCtor, runtime, global_ref);
    }

    if (value->IsArray()) {
        return env->NewObject(classTable.JsArray, classTable.JsArrayCtor, runtime, global_ref);
    }

    if (value->IsMap()) {
        return env->NewObject(classTable.JsMap, classTable.JsMapCtor, runtime, global_ref);
    }

    if (value->IsObject()) {
        return env->NewObject(classTable.JsObject, classTable.JsObjectCtor, runtime, global_ref);
    }

    return nullptr;
}