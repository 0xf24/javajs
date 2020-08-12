package io.manxboy.js.value;

import io.manxboy.js.impl.V8Ref;

public class JsContext extends V8Ref {

    public JsContext(JsRuntime runtime) {
        super(runtime, nativeConstructor(runtime));
    }

    private JsContext(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    public native JsObject global();

    /**
     * "enter" this context
     * evaluates all following javascript method calls (property access/set, function and script evaluation, etc) util {@link #exit()} is called
     */
    public native void enter();

    /**
     * "exits" this context
     */
    public native void exit();

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);

    protected static native long nativeConstructor(JsRuntime runtime);
}
