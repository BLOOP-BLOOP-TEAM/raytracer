cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/ACam.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/AEntity.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ALight.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/APrimitive.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/ScenesManager.cpp"
        )