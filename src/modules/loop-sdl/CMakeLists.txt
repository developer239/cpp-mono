set(LIB_NAME LoopSDL)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

target_link_libraries(${LIB_NAME} PRIVATE Loop)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
target_link_libraries(${LIB_NAME} PRIVATE SDL2)

find_package(SDL2_ttf REQUIRED)
target_link_libraries(${LIB_NAME} PRIVATE SDL2::TTF)
