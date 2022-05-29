set(LIB_NAME SharedLib)

add_library(${LIB_NAME} STATIC
        src/components/BoundingBoxComponent.h
        src/components/TextLabelComponent.h
        src/asset-store/AssetStore.h
        src/systems/RenderTextSystem.h
        src/systems/RenderTextSystem.cpp
        )

target_include_directories(${LIB_NAME} INTERFACE .)

target_link_libraries(${LIB_NAME} PRIVATE ECS)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 2.0.22 EXACT REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf 2.0.18 EXACT REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::TTF)
