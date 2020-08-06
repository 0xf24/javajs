cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(JavaJS_JNI VERSION 1.0 DESCRIPTION "native jni code for the JavaJs project" LANGUAGES CXX C)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DV8_COMPRESS_POINTERS")

find_package(JNI REQUIRED)

add_library(
    JavaJS_JNI SHARED src/util.h src/util.cpp src/JsRuntime.cpp src/JsContext.cpp)

target_include_directories(JavaJS_JNI PUBLIC ${JNI_INCLUDE_DIRS})
target_include_directories(JavaJS_JNI PUBLIC ${CMAKE_SOURCE_DIR}/external/v8/include)
target_include_directories(JavaJS_JNI PUBLIC ${CMAKE_SOURCE_DIR}/include)

find_library(V8_LIB v8 PATHS ${CMAKE_SOURCE_DIR}/external/v8/bin)
find_library(V8_PLATFORM_LIB libv8_libplatform.dylib ${CMAKE_SOURCE_DIR}/external/v8/bin)

target_link_libraries(JavaJS_JNI ${V8_LIB} ${V8_PLATFORM_LIB})
#target_link_directories(JavaJS_JNI PUBLIC ${CMAKE_SOURCE_DIR}/external/v8/bin)
#target_link_libraries(JavaJS_JNI ${CMAKE_SOURCE_DIR}/external/v8/bin/libv8.dylib)

#make result dir
add_custom_target(build-time-make-directory ALL
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/../java/bin/)

#copy result to java source dir
add_custom_command(TARGET JavaJS_JNI POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:JavaJS_JNI> ${CMAKE_SOURCE_DIR}/../java/bin)
