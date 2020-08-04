package io.manxboy.js.impl;

public abstract class V8Ref implements AutoCloseable {
    @SuppressWarnings({"FieldCanBeLocal", "unused"})
    private final long ptr;
    private boolean destroyed = false;

    protected V8Ref(long ptr) {
        this.ptr = ptr;
    }

    protected abstract void nativeDestructor(long ptr);

    @Override
    public void finalize() {
        if (!destroyed) {
            nativeDestructor(ptr);
            destroyed = true;
        }
    }

    @Override
    public void close() throws Exception {
        if (!destroyed) {
            nativeDestructor(ptr);
            destroyed = true;
        }
    }
}
