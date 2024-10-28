file(
    GLOB
    MODULE_SRC_FILES
    "*.c"
)

add_library(
    ${MODULE_LIB}
    STATIC
    ${MODULE_SRC_FILES}
)

target_include_directories(
    ${MODULE_LIB}
    PUBLIC
    ${DRIVER_INC_DIR}
)