package io.manxboy.js.value;

import io.manxboy.js.JsContext;
import io.manxboy.js.JsRuntime;

import java.util.Collection;
import java.util.Map;
import java.util.Set;

public class JsMap extends JsObject {

    protected JsMap(JsRuntime runtime) {
        super(nativeConstructor(runtime));
    }

    private static native long nativeConstructor(JsRuntime runtime);

    @Override
    protected native void nativeDestructor(long ptr);


    public native void clear();

    public native int size();

    public native boolean delete(JsContext context, JsValue key);

    public native JsValue[] entries(JsContext context);

    public native JsValue get(JsContext context, JsValue key);

    public native JsValue set(JsContext context, JsValue key, JsValue value);

    public native JsValue[] keys(JsContext context);

    public native JsValue[] values(JsContext context);
}
