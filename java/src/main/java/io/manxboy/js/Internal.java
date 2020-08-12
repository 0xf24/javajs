package io.manxboy.js;

import java.lang.annotation.*;

/**
 * The annotated element is marked as an internal field, that is not meant to be used or read by consumers of the api
 */
@Retention(RetentionPolicy.RUNTIME)
@Target({ElementType.METHOD, ElementType.CONSTRUCTOR, ElementType.FIELD})
@Documented
public @interface Internal {
}
