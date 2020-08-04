package io.manxboy.js.value;

import io.manxboy.js.JsContext;
import io.manxboy.js.JsRuntime;

public class JsObject extends JsValue {

    protected JsObject(long ptr) {
        super(ptr);
    }

    public JsObject(JsRuntime runtime) {
        super(nativeConstructor(runtime));
    }

    private static native long nativeConstructor(JsRuntime runtime);

    @Override
    protected native void nativeDestructor(long ptr);


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
