package io.manxboy.js.script;

import io.manxboy.js.value.JsContext;
import io.manxboy.js.impl.V8Ref;
import io.manxboy.js.value.JsValue;

public class JsScript extends V8Ref {

    private JsScript(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    /**
     * Compile a script in the following context
     * @param context the context to use
     * @param source the source of the script
     * @return the compiled JsScript
     */
    public static native JsScript compile(JsContext context, String source);

    public native JsValue run();

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);
}
