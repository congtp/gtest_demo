

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
)

include(GoogleTest)
gtest_discover_tests(simple_gtest_exe)