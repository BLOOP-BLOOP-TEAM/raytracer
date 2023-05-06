cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/DisplayModule.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Image.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Calculator.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Skybox.cpp"
        )
