package io.manxboy.js.value;

public class JsSet extends JsObject {

    public JsSet(JsRuntime runtime) {
        super(runtime.ptr, nativeConstructor(runtime.ptr));
    }

    private JsSet(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    private static native long nativeConstructor(long rt_ptr);

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);


    public native int size();
    public native void clear();

    public native void add(JsContext context, JsValue value);
    public native boolean has(JsContext context, JsValue value);

    public native boolean delete(JsContext context, JsValue value);

    public native JsValue[] values(JsContext context);

}
