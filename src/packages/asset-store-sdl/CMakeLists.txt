set(LIB_NAME AssetStoreSDL)

aux_source_directory(./src SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

target_link_libraries(${LIB_NAME} PRIVATE Logger)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 2.0.22 EXACT REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf 2.0.18 EXACT REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::TTF)

find_package(SDL2_image REQUIRED)
target_include_directories(${LIB_NAME} PRIVATE ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC ${SDL2_IMAGE_LIBRARIES})
