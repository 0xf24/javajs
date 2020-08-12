package io.manxboy.js;

import io.manxboy.js.value.JsArray;

public class ScriptOrigin {

    private final String resourceName;
    private final int lineOffset;
    private final int columnOffset;
    private final boolean isCrossOrigin;
    private final int id;
    private final String sourceMapURL;
    private final boolean isWasm;
    private final boolean isModule;
    private final JsArray hostDefinedOptions;

    public String getResourceName() {
        return resourceName;
    }

    public int getLineOffset() {
        return lineOffset;
    }

    public int getColumnOffset() {
        return columnOffset;
    }

    public int getId() {
        return id;
    }

    public String getSourceMapURL() {
        return sourceMapURL;
    }

    public boolean isWasm() {
        return isWasm;
    }

    public boolean isCrossOrigin() {
        return isCrossOrigin;
    }

    public boolean isModule() {
        return isModule;
    }

    public JsArray getHostDefinedOptions() {
        return hostDefinedOptions;
    }

    protected ScriptOrigin(String resourceName, int lineOffset, int columnOffset, boolean isCrossOrigin, int id,
                           String sourceMapURL, boolean isWasm, boolean isModule, JsArray hostDefinedOptions) {
        this.resourceName       = resourceName;
        this.lineOffset         = lineOffset;
        this.columnOffset       = columnOffset;
        this.isCrossOrigin      = isCrossOrigin;
        this.id                 = id;
        this.sourceMapURL       = sourceMapURL;
        this.isWasm             = isWasm;
        this.isModule           = isModule;
        this.hostDefinedOptions = hostDefinedOptions;
    }

    public static class Builder {
        private String resourceName;
        private int lineOffset = 0;
        private int columnOffset = 0;
        private boolean isCrossOrigin = false;
        private int id = 0;
        private String sourceMapURL = null;
        private boolean isWasm = false;
        private boolean isModule = false;
        private JsArray hostDefinedOptions = null;

        public Builder(String name) {
            resourceName = name;
        }

        public Builder lineOffset(int value) {
            lineOffset = value;

            return this;
        }

        public Builder columnOffset(int value) {
            columnOffset = value;

            return this;
        }

        public Builder isCrossOrigin() {
            isCrossOrigin = true;

            return this;
        }

        public Builder id(int value) {
            id = value;

            return this;
        }

        public Builder sourceMapURL(String value) {
            sourceMapURL = value;

            return this;
        }

        public Builder isWasm() {
            isWasm = true;

            return this;
        }

        public Builder isModule() {
            isModule = true;

            return this;
        }

        public Builder hostDefinedProcess(JsArray value) {
            this.hostDefinedOptions = value;

            return this;
        }

        public ScriptOrigin build() {
            return new ScriptOrigin(resourceName, lineOffset, columnOffset, isCrossOrigin, id, sourceMapURL, isWasm, isModule, hostDefinedOptions);
        }
    }
}
