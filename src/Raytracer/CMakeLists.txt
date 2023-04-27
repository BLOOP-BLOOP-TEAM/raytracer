cmake_minimum_required(VERSION 3.13)

project(raytracer)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
        )

target_link_libraries(raytracer sfml-graphics sfml-window sfml-system)

add_subdirectory(Core)
add_subdirectory(Entity)
add_subdirectory(Display)
add_subdirectory(Plugin)
