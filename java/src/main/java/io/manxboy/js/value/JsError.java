package io.manxboy.js.value;

public class JsError extends JsObject {

    public JsError(JsContext context, String message) {
        super(context.getRuntime(), nativeConstructor(context, message));
    }

    private JsError(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    private static native long nativeConstructor(JsContext context, String message);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);
}
