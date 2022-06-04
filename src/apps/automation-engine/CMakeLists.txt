set(APP_NAME AppAutomationEngine)
set(APP_FOLDER_NAME automation-engine)

set(SOURCES
        src/main.cpp
        src/App.cpp
        src/App.h
        src/services/AppState.h src/systems/ScreenSystem.h src/systems/RenderScreenSystem.h src/events/KeyPressedEvent.h src/systems/KeyboardControlSystem.h)

add_executable(${APP_NAME} ${SOURCES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/src/apps/${APP_FOLDER_NAME})

target_link_libraries(${APP_NAME} PRIVATE Loop)
target_link_libraries(${APP_NAME} PRIVATE LoopSDL)
target_link_libraries(${APP_NAME} PRIVATE AssetStoreSDL)
target_link_libraries(${APP_NAME} PRIVATE EntityComponentSystem)
target_link_libraries(${APP_NAME} PRIVATE Events)
target_link_libraries(${APP_NAME} PRIVATE Logger)
target_link_libraries(${APP_NAME} PRIVATE Devices)
target_link_libraries(${APP_NAME} PRIVATE DevicesSDL)

## Dependencies

FindOpenCV(${APP_NAME})

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::TTF)
