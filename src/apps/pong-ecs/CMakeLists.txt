set(APP_NAME AppPongECS)
set(APP_FOLDER_NAME pong-ecs)

set(SOURCES
        src/events/KeyPressedEvent.h
        src/main.cpp
        src/App.cpp src/App.h)

add_executable(${APP_NAME} ${SOURCES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/src/apps/${APP_FOLDER_NAME})

target_link_libraries(${APP_NAME} PRIVATE Loop)
target_link_libraries(${APP_NAME} PRIVATE LoopSDL)
target_link_libraries(${APP_NAME} PRIVATE AssetStoreSDL)
target_link_libraries(${APP_NAME} PRIVATE EntityComponentSystem)
target_link_libraries(${APP_NAME} PRIVATE Events)
target_link_libraries(${APP_NAME} PRIVATE Logger)

target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/externals)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 2.0.22 EXACT REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf 2.0.18 EXACT REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::TTF)
