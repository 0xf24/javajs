package io.manxboy.js.value;

import io.manxboy.js.impl.V8Ref;

public class JsValue extends V8Ref {

    private JsContext context;

    protected JsValue(JsRuntime runtime, long ptr) {
        super(runtime, ptr);
    }

    @Override
    protected native void nativeDestructor(JsRuntime runtime, long ptr);


    public static native JsValue from(JsRuntime runtime, int value);
    public static native JsValue from(JsRuntime runtime, long value);
    public static native JsValue from(JsRuntime runtime, double value);
    public static native JsValue from(JsRuntime runtime, boolean value);
    public static native JsValue from(JsRuntime runtime, String value);

    /**
     * returns undefined value
     * @param runtime the runtime to get the value from
     * @return a javascript undefined value
     */
    public static native JsValue undefined(JsRuntime runtime);

    /**
     * returns null value. named nul because of name restrictions in java
     * @param runtime the runtime to get the value from
     * @return a javascript null value
     */
    public static native JsValue nul(JsRuntime runtime);

    public native double toDouble(JsContext context);
    public native int toInt(JsContext context);
    public native long toLong(JsContext context);

    @Override
    public native String toString();
    public native String toString(JsContext context);
    public native boolean toBoolean(JsContext context);

    /**
     * is equivalent to value === null in JS
     * @return true if null, else false
     */
    public native boolean isNull();

    /**
     * is equivalent to value === undefined in JS
     * @return true if undefined, else false
     */
    public native boolean isUndefined();

    /**
     * equivalent to typeof value === "string" in JS
     * @return true if instance of a string, else false
     */
    public native boolean isString();

    /**
     * equivalent to typeof value === "number" in JS
     * @return true of typeof a number, else false
     */
    public native boolean isNumber();

    /**
     * equivalent to value === true in JS
     * @return true if true, else false
     */
    public native boolean isTrue();

    /**
     * equivalent to value === false in JS
     * @return true if false, else true
     */
    public native boolean isFalse();

    /**
     * get a debug string represent
     * @return
     */
    public native String toDetailString();


    @Override
    public boolean equals(Object object) {
        return object instanceof JsValue && this.equals(object);
    }

    /**
     * performs the javascript strict (triple equals) evaluation between this the specified value
     * @param value the value to compare to
     * @return the comparison result
     */
    public native boolean equals(JsValue value);

    public native boolean looseEquals(JsContext context, JsValue value);

    public native String typeOf();

    public native boolean instanceOf(JsContext context, JsObject object);
}
