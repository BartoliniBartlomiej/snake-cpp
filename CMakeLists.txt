cmake_minimum_required(VERSION 3.16)

project(TerminalSnake
    VERSION 1.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(snake_core
    src/Position.cpp
    src/Direction.cpp
)

target_include_directories(snake_core
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(snake
    src/main.cpp
)

target_link_libraries(snake
    PRIVATE
        snake_core
)

include(CTest)

if(BUILD_TESTING)
    include(FetchContent)

    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
        GIT_SHALLOW TRUE
    )

    FetchContent_MakeAvailable(googletest)

    add_subdirectory(tests)
endif()