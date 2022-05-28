cmake_minimum_required(VERSION 3.22)
project(CppMono LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

enable_testing()

add_subdirectory(src)

# TODO: move to separate file
function(checkIfCompilerSupported)
    set(SUPPORTED_COMPILER
            "AppleClang"
            )

    if (NOT CMAKE_CXX_COMPILER_ID IN_LIST SUPPORTED_COMPILER)
        message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif ()
endfunction()

checkIfCompilerSupported()
