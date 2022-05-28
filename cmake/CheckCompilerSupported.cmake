function(CheckCompilerSupported)
    set(SUPPORTED_COMPILER
            "AppleClang"
            )

    if (NOT CMAKE_CXX_COMPILER_ID IN_LIST SUPPORTED_COMPILER)
        message(FATAL_ERROR "Unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
    endif ()
endfunction()
