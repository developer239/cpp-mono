set(APP_NAME AppAutomationEngine)
set(APP_FOLDER_NAME automation-engine)

set(SOURCES
        src/components/BoundingBoxComponent.h
        src/components/TextLabelComponent.h
        src/events/CollisionEvent.h
        src/events/KeyPressedEvent.h
        src/services/AppState.h
        src/services/Lua.h
        src/structs/DetectColorsArguments.h
        src/structs/ErodeDilateArguments.h
        src/structs/Target.h
        src/systems/DetectionSystem.h
        src/systems/KeyboardControlSystem.h
        src/systems/RenderBoundingBoxSystem.h
        src/systems/RenderScreenSystem.h
        src/systems/ScreenSystem.h
        src/systems/ScriptSystem.h
        src/App.cpp
        src/App.h
        src/main.cpp
        )

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

## Lua & Sol

find_package(Lua REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/externals ${LUA_INCLUDE_DIR})
target_link_libraries(${APP_NAME} PUBLIC ${LUA_LIBRARY})