package io.manxboy.js.value;

public class JsObject extends JsValue {

    protected JsObject(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    public JsObject(JsRuntime runtime) {
        super(runtime.ptr, nativeConstructor(runtime.ptr));
    }

    private static native long nativeConstructor(long rt_ptr);

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);


    public native JsValue get(String key);
    public native JsValue get(JsSymbol key);
    public native JsValue get(int index);

    public native void set(String key, JsValue value);
    public native void set(JsSymbol key, JsValue value);
    public native void set(int index, JsValue value);

    public native boolean delete(String key);
    public native boolean delete(JsSymbol key);
    public native boolean delete(int index);

//    public native boolean has(JsContext context, JsValue key);
}
