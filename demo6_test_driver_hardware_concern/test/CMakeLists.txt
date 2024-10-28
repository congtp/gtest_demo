

file(
    GLOB
    SRC_FILES
    "*.cpp"
)

add_executable(
    simple_gtest_exe
    ${SRC_FILES}
)
target_link_libraries(
    simple_gtest_exe    
    GTest::gtest_main
    ${MODULE_LIB}
)

target_include_directories(
    simple_gtest_exe
    PUBLIC
    ${DRIVER_INC_DIR}
)

include(GoogleTest)
gtest_discover_tests(simple_gtest_exe)