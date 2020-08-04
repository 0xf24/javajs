package io.manxboy.js.value;

import io.manxboy.js.JsRuntime;
import io.manxboy.js.value.JsObject;

public class JsError extends JsObject {
    public JsError(JsRuntime runtime, String message) {
        super(nativeConstructor(runtime, message));
    }

    private static native long nativeConstructor(JsRuntime runtime, String message);

    @Override
    protected native void nativeDestructor(long ptr);
}
