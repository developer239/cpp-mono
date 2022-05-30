set(APP_NAME AppPong)
set(APP_FOLDER_NAME pong)

set(SOURCES
        src/main.cpp
        src/App.cpp
        src/App.h
        src/entities/GameObject.h)

add_executable(${APP_NAME} ${SOURCES})

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR}/src/apps/${APP_FOLDER_NAME})

target_link_libraries(${APP_NAME} PRIVATE Loop)
target_link_libraries(${APP_NAME} PRIVATE LoopSDL)
target_link_libraries(${APP_NAME} PRIVATE AssetStoreSDL)
target_link_libraries(${APP_NAME} PRIVATE Logger)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf REQUIRED)
target_include_directories(${APP_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${APP_NAME} PUBLIC SDL2::TTF)
