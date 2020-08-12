package io.manxboy.js.test;

import io.manxboy.js.script.JsScript;
import io.manxboy.js.value.JsContext;
import io.manxboy.js.value.JsObject;
import io.manxboy.js.value.JsRuntime;
import io.manxboy.js.value.JsValue;

public class Main {

    public static void main(String[] args) {
        JsRuntime runtime = new JsRuntime();

        JsContext context = new JsContext(runtime);

        JsScript script = JsScript.compile(context, "foo.bar(3)");

        System.out.println(script.run(context).toString());

//        JsValue value = JsValue.from(runtime, "test");
//
//        JsValue key = JsValue.from(runtime, "foo");
//
//        JsObject object = new JsObject(context);
//
//        object.set(context, "foo", value);
//
//        System.out.println(object.get(context, key).isNull());
//
//        System.out.println(object.get(context, key).toString(context));
//
//        try {
//            Thread.sleep(4000);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }

        runtime.close();
    }
}
