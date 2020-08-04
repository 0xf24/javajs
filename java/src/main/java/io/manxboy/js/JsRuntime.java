package io.manxboy.js;

import io.manxboy.js.impl.V8Ref;
import io.manxboy.js.value.JsPromise;

public class JsRuntime extends V8Ref {

    static {
        System.loadLibrary("JavaJS_JNI");
    }

    public JsRuntime() {
        super(nativeConstructor());
    }

    private static native long nativeConstructor();

    @Override
    protected native void nativeDestructor(long ptr);


    @FunctionalInterface
    public interface HostModuleImportDynamic {
        JsPromise importModule(JsContext context, String specifier);
    }
}
