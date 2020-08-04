package io.manxboy.js.value;

import io.manxboy.js.JsContext;
import io.manxboy.js.value.JsObject;
import io.manxboy.js.value.JsValue;

import javax.annotation.CheckForNull;

public class JsFunction extends JsObject {


    private JsFunction(long ptr) {
        super(ptr);
    }

    @Override
    protected native void nativeDestructor(long ptr);


    /**
     * create a new Instance using this "constructor"
     * @param context the context in which to construct
     * @return a new object
     */
    @CheckForNull
    public native JsObject newInstance(JsContext context);

    /**
     * create a new Instance using this "constructor"
     * @param context the context in which to construct
     * @param args the arguments to use
     * @return a new object
     */
    @CheckForNull
    public native JsObject newInstance(JsContext context, JsValue ...args);

    /**
     * call this function
     * @param context the context in which to call
     * @param target the target? receiver?
     * @param args the arguments to use
     * @return the return value of this function, or null
     */
    @CheckForNull
    public native JsValue call(JsContext context, JsValue target, JsValue ...args);

    public native int getScriptLineNumber();

    public native int getScriptColumnNumber();

    public native JsValue getName();

    public native JsValue getInferredName();

    public native JsValue getDisplayName();

    public native JsValue getDebugName();

    public native JsValue getBoundFunction();
}
