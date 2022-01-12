cmake_minimum_required(VERSION 3.16)
project(DontMarryFrameworks)

set(CMAKE_CXX_STANDARD 17)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
conan_basic_setup()
 
enable_testing()
add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/gtest)