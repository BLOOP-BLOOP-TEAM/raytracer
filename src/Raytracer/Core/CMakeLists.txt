cmake_minimum_required(VERSION 3.13)

target_include_directories(raytracer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_sources(raytracer PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Core.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FactoryEntity.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/LoadConfig.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/EventManager.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/FactoryMaterial.cpp"
        )
