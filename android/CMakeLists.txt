cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)
set(PACKAGE_NAME ijsi)
set(BUILD_DIR ./build)
set(RNSO_DIR ${BUILD_DIR}/react-native-libs/jni/${ANDROID_ABI})

set(FBJNI_HEADERS_DIR ${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/jni/first-party/fbjni/headers)

add_library(
        ${PACKAGE_NAME}
        SHARED
        ../cpp/react-native-ijsi.cpp
        cpp-adapter.cpp
)
file (GLOB LIBFBJNI_INCLUDE_DIR ${FBJNI_HEADERS_DIR})
target_include_directories(
        ${PACKAGE_NAME}
        PRIVATE
        ../cpp
        "${LIBFBJNI_INCLUDE_DIR}"
        "${NODE_MODULES_DIR}/react-native/React"
        "${NODE_MODULES_DIR}/react-native/React/Base"
        "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/jni"
        "${NODEMODULES_DIR}/react-native/ReactCommon"
        "${NODEMODULES_DIR}/react-native/ReactCommon/jsi"
)
find_library(
        LOG
        log
)
find_library(
        JSI
        jsi
        PATHS ${RNSO_DIR}
        NO_CMAKE_FIND_ROOT_PATH
)
find_library(
        FBJNI
        fbjni
        PATHS ${RNSO_DIR}
        NO_CMAKE_FIND_ROOT_PATH
)
target_link_libraries(
        ${PACKAGE_NAME}
        ${JSI}
        ${LOG}
        ${FBJNI}
)
