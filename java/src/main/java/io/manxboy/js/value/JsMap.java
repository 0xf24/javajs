package io.manxboy.js.value;

public class JsMap extends JsObject {

    public JsMap(JsRuntime runtime) {
        super(runtime.ptr, nativeConstructor(runtime.ptr));
    }

    private JsMap(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    private static native long nativeConstructor(long rt_ptr);

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);


    public native void clear();

    public native int size();

    public native boolean delete(JsContext context, JsValue key);

    public native JsValue[] entries(JsContext context);

    public native JsValue get(JsContext context, JsValue key);

    public native JsValue set(JsContext context, JsValue key, JsValue value);

    public native JsValue[] keys(JsContext context);

    public native JsValue[] values(JsContext context);
}
