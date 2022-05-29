set(APP_NAME AppFirstCppMono)

set(SOURCES
        src/events/KeyPressedEvent.h
        src/systems/KeyboardControlSystem.h
        src/main.cpp
        src/App.cpp src/App.h)

add_executable(${APP_NAME} ${SOURCES})

target_link_libraries(${APP_NAME} PRIVATE Loop)
target_link_libraries(${APP_NAME} PRIVATE LoopSDL)
target_link_libraries(${APP_NAME} PRIVATE EntityComponentSystem)
target_link_libraries(${APP_NAME} PRIVATE Events)
target_link_libraries(${APP_NAME} PRIVATE Logger)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 2.0.22 EXACT REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf 2.0.18 EXACT REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::TTF)
