package io.manxboy.js.value;

public class JsArray extends JsObject {

    public JsArray(JsRuntime runtime) {
        this(runtime, 0);
    }

    public JsArray(JsRuntime runtime, int length) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, length));
    }

    public JsArray(JsRuntime runtime, JsValue[] values) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, values));
    }

    private JsArray(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    public native int length();

    private static native long nativeConstructor(long rt_ptr, int length);

    private static native long nativeConstructor(long rt_ptr, JsValue[] values);

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);

}
