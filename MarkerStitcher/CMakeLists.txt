cmake_minimum_required(VERSION 3.20)
project(MarkerStitcher)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Пути к PCL и Boost
set(PCL_DIR "C:/vcpkg/installed/x64-windows/share/pcl" CACHE PATH "PCL config directory")
set(BOOST_ROOT "C:/vcpkg/installed/x64-windows")
set(Boost_NO_SYSTEM_PATHS ON)

# ВАЖНО: указываем путь к VTK конфигурации
set(VTK_DIR "C:/vcpkg/installed/x64-windows/share/vtk" CACHE PATH "VTK config directory")

# PCL сам найдет VTK через компонент visualization
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