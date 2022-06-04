set(LIB_NAME DevicesSDL)

aux_source_directory(./src SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

## Dependencies

FindOpenCV(${LIB_NAME})

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::TTF)

find_package(SDL2_image REQUIRED)
target_include_directories(${LIB_NAME} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC ${SDL2_IMAGE_LIBRARIES})
