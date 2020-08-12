package io.manxboy.js.value;

public class JsSymbol extends JsValue {

    public JsSymbol(JsRuntime runtime, String description) {
        super(runtime, nativeConstructor(runtime, description));
    }

    private JsSymbol(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    private static native long nativeConstructor(JsRuntime runtime, String description);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);


    public static native JsSymbol forKey(JsRuntime runtime, String description);

    public static native JsSymbol getAsyncIterator(JsRuntime runtime);

    public static native JsSymbol getHasInstance(JsRuntime runtime);

    public static native JsSymbol getIsConcatSpreadable(JsRuntime runtime);

    public static native JsSymbol getIterator(JsRuntime runtime);

    public static native JsSymbol getMatch(JsRuntime runtime);

    public static native JsSymbol getReplace(JsRuntime runtime);

    public static native JsSymbol getSearch(JsRuntime runtime);

    public static native JsSymbol getSplit(JsRuntime runtime);

    public static native JsSymbol getToPrimitive(JsRuntime runtime);

    public static native JsSymbol getToStringTag(JsRuntime runtime);

    public static native JsSymbol getUnscopables(JsRuntime runtime);

}
