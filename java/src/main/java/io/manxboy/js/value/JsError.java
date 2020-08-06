package io.manxboy.js.value;

public class JsError extends JsObject {

    public JsError(JsRuntime runtime, String message) {
        super(runtime.ptr, nativeConstructor(runtime.ptr, message));
    }

    private JsError(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    private static native long nativeConstructor(long rt_ptr, String message);

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);
}
