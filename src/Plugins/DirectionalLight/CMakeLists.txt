cmake_minimum_required(VERSION 3.13)

target_include_directories(plugin_directional_light PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(plugin_directional_light PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/DirectionalLight.cpp"
        )
