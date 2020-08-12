package io.manxboy.js;

import io.manxboy.js.value.JsContext;
import io.manxboy.js.value.JsRuntime;

public interface JsLogger {

    /**
     * logs messages from javascript `console.log`
     * @param runtime the runtime which called
     * @param message the message to log
     */
    void log(JsRuntime runtime, String message);

    /**
     * logs messages from javascript `console.err`
     * @param runtime the runtime which called
     * @param message the message to log
     */
    void error(JsRuntime runtime, String message);
}
