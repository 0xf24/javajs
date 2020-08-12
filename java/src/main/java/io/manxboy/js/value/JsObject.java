package io.manxboy.js.value;

import io.manxboy.js.Internal;
import io.manxboy.js.PropertyDescriptor;

import javax.annotation.CheckForNull;
import javax.annotation.Nullable;

public class JsObject extends JsValue {

    /**
     *
     * @param runtime
     * @param ptr
     */
    @Internal
    protected JsObject(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    /**
     * Create a new javascript object in the specified context
     * @param context the context to use
     */
    public JsObject(JsContext context) {
        this(context, null);
    }

    public JsObject(JsContext context, @Nullable JsValue prototype) {
        super(context.getRuntime(), nativeConstructor(context, prototype));
    }

    private static native long nativeConstructor(JsContext context, @Nullable JsValue prototype);

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);


    public native JsValue get(JsContext context, String key);
    public native JsValue get(JsContext context, JsValue key);
    public native JsValue get(JsContext context, int index);

    public native void set(JsContext context, String key, JsValue value);
    public native void set(JsContext context, JsValue key, JsValue value);
    public native void set(JsContext context, int index, JsValue value);

    public native boolean delete(JsContext context, String key);
    public native boolean delete(JsContext context, JsValue key);
    public native boolean delete(JsContext context, int index);

    public native boolean has(JsContext context, String key);
    public native boolean has(JsContext context, JsValue key);
    public native boolean has(JsContext context, int index);

    public native boolean defineProperty(JsContext context, String key, PropertyDescriptor descriptor);

    public native boolean defineProperty(JsContext context, JsValue key, PropertyDescriptor descriptor);

    @CheckForNull
    public static native PropertyDescriptor getOwnPropertyDescriptor(JsContext context, JsObject obj, JsValue key);

    public static native String[] getOwnPropertyNames(JsContext context, JsObject object);

    public static native JsSymbol[] getOwnPropertySymbols(JsContext context, JsObject object);

    public static native JsArray keys(JsContext context, JsObject object);

//    public static native JsObject getPrototypeOf(JsContext context, JsObject object);

    public native JsObject getPrototype();

    public static native void seal(JsContext context, JsObject object);

    public static native void freeze(JsContext context, JsObject object);

//    public native boolean has(JsContext context, JsValue key);
}
