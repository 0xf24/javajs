package io.manxboy.js.value;

import io.manxboy.js.JsContext;
import io.manxboy.js.JsRuntime;

public class JsSet extends JsObject {

    public JsSet(JsRuntime runtime) {
        super(nativeConstructor(runtime));
    }

    private static native long nativeConstructor(JsRuntime runtime);

    @Override
    protected native void nativeDestructor(long ptr);


    public native int size();
    public native void clear();

    public native void add(JsContext context, JsValue value);
    public native boolean has(JsContext context, JsValue value);

    public native boolean delete(JsContext context, JsValue value);

    public native JsValue[] values(JsContext context);

}
