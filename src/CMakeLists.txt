cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(Raytracer)
add_subdirectory(Plugins)
add_subdirectory(libs)

target_include_directories(raytracer PRIVATE ${STB_IMAGE_INCLUDE_DIR})
