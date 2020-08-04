package io.manxboy.js.script;

import io.manxboy.js.JsContext;
import io.manxboy.js.value.JsValue;

public class JsScript {

    /**
     * Compile a script in the following context
     * @param context the context to use
     * @param source the source of the script
     * @return the compiled JsScript
     */
    public static native JsScript compile(JsContext context, String source);

    public native JsValue run();

}
