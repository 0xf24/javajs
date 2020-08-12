package io.manxboy.js.script;

import io.manxboy.js.ScriptOrigin;
import io.manxboy.js.value.JsContext;
import io.manxboy.js.impl.V8Ref;
import io.manxboy.js.value.JsRuntime;
import io.manxboy.js.value.JsValue;

import javax.annotation.Nullable;

public class JsScript extends V8Ref {

    private JsScript(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    /**
     * Compile a script in the following context
     * @param context the context to use
     * @param source the source of the script
     * @return the compiled JsScript
     */
    public static native JsScript compile(JsContext context, String source);

    public static native JsScript compile(JsContext context, String source, ScriptOrigin origin);

    public native JsValue run(JsContext context);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);
}
