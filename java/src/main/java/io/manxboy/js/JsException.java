package io.manxboy.js;

import io.manxboy.js.value.JsError;

public class JsException extends Exception {

    private JsError error;

    private JsException(String message, JsError error) {
        super(message);
        this.error = error;
    }

    public JsError getError() {
        return error;
    }

}
