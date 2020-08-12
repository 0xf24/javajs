package io.manxboy.js.value;

public class JsMap extends JsObject {

    public JsMap(JsContext context) {
        super(context.getRuntime(), nativeConstructor(context));
    }

    private JsMap(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    private static native long nativeConstructor(JsContext context);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);

    public native void clear();

    public native int size();

    public native boolean mapDelete(JsContext context, JsValue key);

    public native JsValue[] entries(JsContext context);

    public native JsValue mapGet(JsContext context, JsValue key);

    public native JsValue mapSet(JsContext context, JsValue key, JsValue value);

    public native JsValue[] keys(JsContext context);

    public native JsValue[] values(JsContext context);
}
