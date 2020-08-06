package io.manxboy.js.value;

import io.manxboy.js.impl.V8Ref;

public class JsValue extends V8Ref {

    private JsContext context;

    protected JsValue(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);

    public JsValue (JsRuntime runtime, int value) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, value));
    }

    public JsValue (JsRuntime runtime, long value) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, value));
    }

    public JsValue (JsRuntime runtime, double value) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, value));
    }

    public JsValue (JsRuntime runtime, boolean value) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, value));
    }

    public JsValue (JsRuntime runtime, String value) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, value));
    }

    private static native long nativeConstructor(long rt_ptr, int value);
    private static native long nativeConstructor(long rt_ptr, long value);
    private static native long nativeConstructor(long rt_ptr, double value);
    private static native long nativeConstructor(long rt_ptr, boolean value);
    private static native long nativeConstructor(long rt_ptr, String value);

    public native double toDouble();
    public native long toInt();

    @Override
    public native String toString();
    public native boolean toBoolean();

    /**
     * get a debug string represent
     * @return
     */
    public native String toDetailString();

    @Override
    public boolean equals(Object object) {
        return object instanceof JsValue && this.equals(object);
    }

    public native boolean equals(JsValue value);

    public native boolean strictEquals(JsValue value);

    public native String typeOf(JsRuntime runtime);
}
