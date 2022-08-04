cmake_minimum_required(VERSION 3.22)
include(ExternalProject)

project(testmetal)

find_library(AppKit AppKit)
find_library(Foundation Foundation)
find_library(Metal Metal)
find_library(QuartzCore QuartzCore)

set(CUR_TARGET testmetal)
add_executable(${CUR_TARGET} MACOSX_BUNDLE ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/view_delegate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/app_delegate.cpp)
set_target_properties(${CUR_TARGET} PROPERTIES
    BUNDLE True
    MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.${CUR_TARGET}
    MACOSX_BUNDLE_BUNDLE_NAME ${CUR_TARGET}
    MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/MacOSXBundleInfo.plist.in
)
target_include_directories(${CUR_TARGET} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/metal-cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/metal-cpp-extensions)
target_compile_features(${CUR_TARGET} PRIVATE cxx_std_17)
target_link_libraries(
    ${CUR_TARGET}
    ${AppKit}
    ${Foundation}
    ${QuartzCore}
    ${Metal})
