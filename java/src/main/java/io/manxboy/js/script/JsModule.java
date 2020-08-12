package io.manxboy.js.script;

import io.manxboy.js.impl.V8Ref;
import io.manxboy.js.value.JsRuntime;

public class JsModule extends V8Ref {

    private JsModule(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);
}
