package io.manxboy.js.value;

import io.manxboy.js.JsRuntime;
import io.manxboy.js.value.JsValue;

public class JsSymbol extends JsValue {

    public JsSymbol(JsRuntime runtime, String description) {
        super(nativeConstructor(runtime, description));
    }

    private static native long nativeConstructor(JsRuntime runtime, String description);

    @Override
    protected native void nativeDestructor(long ptr);


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
