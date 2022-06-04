set(LIB_NAME Devices)

aux_source_directory(./src SRC_FILES)

add_library(${LIB_NAME} STATIC ${SRC_FILES})

target_include_directories(${LIB_NAME} INTERFACE .)

FindOpenCV(${LIB_NAME})
