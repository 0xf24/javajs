package io.manxboy.js.test;

import io.manxboy.js.value.JsContext;
import io.manxboy.js.value.JsRuntime;

public class Main {

    public static void main(String[] args) {
        JsRuntime runtime = new JsRuntime();

        JsContext context = new JsContext(runtime);

        try {
            Thread.sleep(4000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        runtime.close();
    }
}
