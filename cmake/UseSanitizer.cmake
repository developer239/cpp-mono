option(USE_SANITIZATION "If ON is compiled with sanitization" OFF)

if ($CACHE{USE_SANITIZATION})
    if (CMAKE_CXX_COMPILER_ID MATCHES GNU)
        message("Adding sanitization for GNU compiler")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
        set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
    endif ()
else ()
    message("Skipping sanitization")
endif ()

