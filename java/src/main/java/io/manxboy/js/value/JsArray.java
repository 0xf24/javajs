package io.manxboy.js.value;

public class JsArray extends JsObject {

    public JsArray(JsContext context) {
        this(context, 0);
    }

    public JsArray(JsContext context, int length) {
        super(context.getRuntime(), nativeConstructor(context, length));
    }

    public JsArray(JsContext context, JsValue[] values) {
        super(context.getRuntime(), nativeConstructor(context, values));
    }

    private JsArray(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    public native int length();

    private static native long nativeConstructor(JsContext runtime, int length);

    private static native long nativeConstructor(JsContext context, JsValue[] values);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);

}
