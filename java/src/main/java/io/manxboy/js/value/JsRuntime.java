package io.manxboy.js.value;

public class JsRuntime implements AutoCloseable {

    final long ptr;
    private boolean destroyed = false;

    @Override
    public void finalize() {
        if (!destroyed) {
            nativeDestructor(ptr);
            destroyed = true;
        }
    }

    @Override
    public void close() {
        if (!destroyed) {
            nativeDestructor(ptr);
            destroyed = true;
        }
    }

    static {
        System.loadLibrary("JavaJS_JNI");
    }

    public JsRuntime() {
        this.ptr = nativeConstructor();
    }

    private static native long nativeConstructor();

    protected native void nativeDestructor(long ptr);


    @FunctionalInterface
    public interface HostModuleImportDynamic {
        JsPromise importModule(JsContext context, String specifier);
    }
}
