cmake_minimum_required(VERSION 3.13)
project(
        Raytracer
        VERSION 1.0
        DESCRIPTION "Epitech raytracer project"
        LANGUAGES CXX
)

##############################################################################
# Raytracer binary
add_executable(raytracer src/Raytracer/Entity/IPrimitive.hpp)
set_target_properties(raytracer PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        )

add_custom_command(TARGET raytracer PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/plugins $<TARGET_FILE_DIR:raytracer>/plugins
        )

##############################################################################
# Plugin .so libs
add_library(plugin_sphere SHARED src/Raytracer/Entity/IPrimitive.hpp)
set_target_properties(plugin_sphere PROPERTIES
        CXX_STANDARD 20
        COMPILE_FLAGS "-fno-gnu-unique"
        PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/plugins"
        )

add_subdirectory(src)
