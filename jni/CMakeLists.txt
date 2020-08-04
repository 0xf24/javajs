cmake_minimum_required(VERSION 3.1)

project(JavaJS_JNI VERSION 1.0 DESCRIPTION "native jni code for the JavaJs project" LANGUAGES CXX C)

find_package(JNI REQUIRED)

add_library(
    JavaJS_JNI SHARED src/util.h src/util.cpp src/JsRuntime.cpp)

target_include_directories(JavaJS_JNI PUBLIC ${JNI_INCLUDE_DIRS})
target_include_directories(JavaJS_JNI PUBLIC ${CMAKE_SOURCE_DIR}/external/v8/include)
target_include_directories(JavaJS_JNI PUBLIC ${CMAKE_SOURCE_DIR}/include)

#make result dir
add_custom_target(build-time-make-directory ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/../java/bin/)

#copy result to java source dir
add_custom_command(TARGET JavaJS_JNI POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:JavaJS_JNI> ${CMAKE_SOURCE_DIR}/../java/bin)
