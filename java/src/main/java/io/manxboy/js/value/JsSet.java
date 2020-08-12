package io.manxboy.js.value;

public class JsSet extends JsObject {

    public JsSet(JsContext context) {
        super(context.getRuntime(), nativeConstructor(context));
    }

    private JsSet(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    private static native long nativeConstructor(JsContext context);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);


    public native int size();
    public native void clear();

    public native void add(JsContext context, JsValue value);
    public native boolean has(JsContext context, JsValue value);

    public native boolean delete(JsContext context, JsValue value);

    public native JsValue[] values(JsContext context);

}
