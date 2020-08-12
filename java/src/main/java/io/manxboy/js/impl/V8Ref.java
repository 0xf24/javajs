package io.manxboy.js.impl;

import io.manxboy.js.value.JsRuntime;

public abstract class V8Ref implements AutoCloseable {
    @SuppressWarnings({"FieldCanBeLocal", "unused"})
    private final long ptr;

    @SuppressWarnings({"FieldCanBeLocal", "unused"})
    //private final long rt_ptr;

    private final JsRuntime runtime;

    private boolean destroyed = false;

    protected V8Ref(JsRuntime runtime, long ptr) {
        this.ptr = ptr;
        this.runtime = runtime;
    }

    protected abstract void nativeDestructor(JsRuntime runtime, long ptr);

    @Override
    public void finalize() {
        if (!destroyed) {
            nativeDestructor(runtime, ptr);
            destroyed = true;
        }
    }

    @Override
    public void close() {
        if (!destroyed) {
            nativeDestructor(runtime, ptr);
            destroyed = true;
        }
    }

    public JsRuntime getRuntime() {
        return runtime;
    }
}
