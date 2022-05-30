cmake_minimum_required(VERSION 3.19)
project(CppMono LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(CheckCompilerSupported)
include(UseCodeCoverage)
include(UseCodeCoverage)

CheckCompilerSupported()
enable_testing()

add_subdirectory(externals EXCLUDE_FROM_ALL)
add_subdirectory(src)
