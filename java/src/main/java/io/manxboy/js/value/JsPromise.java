package io.manxboy.js.value;

import io.manxboy.js.value.JsObject;
import io.manxboy.js.value.JsValue;

public class JsPromise<T extends JsValue> extends JsObject {

    private JsPromise(long rt_ptr, long ptr) {
        super(rt_ptr, ptr);
    }

    @Override
    protected native void nativeDestructor(long rt_ptr, long ptr);


}
