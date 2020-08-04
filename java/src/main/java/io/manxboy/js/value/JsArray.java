package io.manxboy.js.value;

import io.manxboy.js.JsRuntime;
import io.manxboy.js.value.JsObject;

public class JsArray extends JsObject {

    public JsArray(JsRuntime runtime) {
        this(runtime, 0);
    }

    public JsArray(JsRuntime runtime, int length) {
        super(nativeConstructor(runtime, length));
    }

    public JsArray(JsRuntime runtime, JsValue[] values) {
        super(nativeConstructor(runtime, values));
    }

    public native int length();

    private static native long nativeConstructor(JsRuntime runtime, int length);

    private static native long nativeConstructor(JsRuntime runtime, JsValue[] values);

    @Override
    protected native void nativeDestructor(long ptr);

}
