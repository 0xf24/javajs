package io.manxboy.js.value;

import io.manxboy.js.value.JsObject;
import io.manxboy.js.value.JsValue;

public class JsPromise<T extends JsValue> extends JsObject {

    private JsPromise(long ptr) {
        super(ptr);
    }

    @Override
    protected native void nativeDestructor(long ptr);


}
