cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_sphere PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_cylinder PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_triangle PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_plane PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_perspective_camera PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_point_light PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_simple_material PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_reflect_material PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_plane_material PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(plugin_directional_light PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/RaytracerException.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Text.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp"
        )

target_sources(plugin_simple_material PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_reflect_material PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_point_light PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_directional_light PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_perspective_camera PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        )

target_sources(plugin_sphere PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )
        
target_sources(plugin_plane PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_plane_material PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_cylinder PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        )

target_sources(plugin_triangle PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Vector3f.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp"
        )

add_subdirectory(Core)
add_subdirectory(Entity)
add_subdirectory(Display)
add_subdirectory(Plugin)
add_subdirectory(Observer)
