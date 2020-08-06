package io.manxboy.js.value;

import io.manxboy.js.impl.V8Ref;

public class JsContext extends V8Ref {

    private final JsRuntime runtime;

    public JsContext(JsRuntime runtime) {
        super(runtime.ptr, nativeConstructor(runtime.ptr));
        this.runtime = runtime;
    }

    private JsContext(JsRuntime runtime, long ptr) {
        super(runtime.ptr, ptr);
        this.runtime = runtime;
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
    protected native void nativeDestructor(long rt_ptr, long ptr);

    protected static native long nativeConstructor(long rt_ptr);
}
