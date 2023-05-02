cmake_minimum_required(VERSION 3.13)

project(raytracer)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
        )

add_subdirectory(Core)
add_subdirectory(Entity)
add_subdirectory(Display)
add_subdirectory(Plugin)
add_subdirectory(Observer)
