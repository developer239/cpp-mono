set(LIB_NAME LoopSDL)

aux_source_directory(. SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

target_link_libraries(${LIB_NAME} PRIVATE Loop)
target_link_libraries(${LIB_NAME} PRIVATE Logger)

target_link_libraries(${LIB_NAME} PRIVATE ImGui)

## SDL2

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

find_package(SDL2 REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::Main)

find_package(SDL2_ttf REQUIRED)
target_include_directories(${LIB_NAME} PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${LIB_NAME} PUBLIC SDL2::TTF)

## ImGui

# TODO: Ideally make custom ImGui cmake file

set(IMGUI_PATH "externals/imgui")

file(GLOB IMGUI_SOURCES ${IMGUI_PATH}/*.cpp)
add_library("ImGui" STATIC ${IMGUI_SOURCES})
target_include_directories("ImGui" PUBLIC ${IMGUI_PATH} ${SDL2_INCLUDE_DIRS})

target_link_libraries(${LIB_NAME} PUBLIC ImGui)
