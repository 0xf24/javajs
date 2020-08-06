package io.manxboy.js.script;

import io.manxboy.js.impl.V8Ref;

public class JsModule extends V8Ref {

    private JsModule(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);
}
