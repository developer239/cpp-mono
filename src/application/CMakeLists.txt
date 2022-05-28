set(APP_NAME CppMonoApp)

aux_source_directory(. SRC_FILES)

add_executable(${APP_NAME} ${SRC_FILES})

target_link_libraries(${APP_NAME} PRIVATE Core)
target_link_libraries(${APP_NAME} PRIVATE CoreSDLImplementation)
target_link_libraries(${APP_NAME} PRIVATE Events)
