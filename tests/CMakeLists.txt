add_executable(snake_tests
    PositionTest.cpp
)

target_link_libraries(snake_tests
    PRIVATE
        snake_core
        GTest::gmock_main
)

include(GoogleTest)

gtest_discover_tests(snake_tests)