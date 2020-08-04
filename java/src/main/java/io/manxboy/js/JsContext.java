package io.manxboy.js;

import io.manxboy.js.impl.V8Ref;
import io.manxboy.js.value.JsObject;

public class JsContext extends V8Ref {

    public JsContext(JsRuntime runtime) {
        super(nativeConstructor(runtime));
    }

    private JsContext(long ptr) {
        super(ptr);
    }

    public native JsObject global();

    public native JsRuntime getRuntime();

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
    protected native void nativeDestructor(long ptr);

    protected static native long nativeConstructor(JsRuntime runtime);
}
