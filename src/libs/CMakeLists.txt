cmake_minimum_required(VERSION 3.13)

set(STB_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" PARENT_SCOPE)

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/stb_image_wrapper.cpp"
        )
