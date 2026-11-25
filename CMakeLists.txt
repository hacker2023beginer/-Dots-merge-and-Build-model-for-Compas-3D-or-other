cmake_minimum_required(VERSION 3.20)

# ОБЯЗАТЕЛЬНО до вызова project()
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

project(MarkerStitcher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/table_scene_lms400.pcd 
               ${CMAKE_CURRENT_BINARY_DIR}/table_scene_lms400.pcd COPYONLY)

find_package(PCL REQUIRED COMPONENTS 
    common 
    io 
    visualization
    kdtree
    search
    filters
)

add_executable(MarkerStitcher main.cpp)

target_include_directories(MarkerStitcher PRIVATE ${PCL_INCLUDE_DIRS})
target_link_libraries(MarkerStitcher PRIVATE ${PCL_LIBRARIES})
target_compile_definitions(MarkerStitcher PRIVATE ${PCL_DEFINITIONS})
