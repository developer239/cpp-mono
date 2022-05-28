set(APP_NAME CppMonoApp)

add_subdirectory(core)
add_subdirectory(core-sdl-implement)
add_subdirectory(event-bus)

set(SRC_FILES
        main.cpp
        )

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE Core)
target_link_libraries(${APP_NAME} PRIVATE CoreSDLImplementation)
target_link_libraries(${APP_NAME} PRIVATE EventBus)
