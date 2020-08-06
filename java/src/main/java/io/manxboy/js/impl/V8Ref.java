package io.manxboy.js.impl;

public abstract class V8Ref implements AutoCloseable {
    @SuppressWarnings({"FieldCanBeLocal", "unused"})
    private final long ptr;

    @SuppressWarnings({"FieldCanBeLocal", "unused"})
    private final long rt_ptr;

    private boolean destroyed = false;

    protected V8Ref(long rt_ptr, long ptr) {
        this.ptr = ptr;
        this.rt_ptr = rt_ptr;
    }

    protected abstract void nativeDestructor(long rt_ptr, long ptr);

    @Override
    public void finalize() {
        if (!destroyed) {
            nativeDestructor(rt_ptr, ptr);
            destroyed = true;
        }
    }

    @Override
    public void close() {
        if (!destroyed) {
            nativeDestructor(rt_ptr, ptr);
            destroyed = true;
        }
    }
}
