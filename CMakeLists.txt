
cmake_minimum_required(VERSION 3.20)

project(StudentManagement
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable compiler warnings
function(enable_project_warnings target)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
        )
    elseif(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    endif()
endfunction()

# Create a reusable Student library
add_library(student_lib
    src/Student.cpp
)

target_include_directories(student_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src
)

enable_project_warnings(student_lib)

# Main application
add_executable(student_app
    src/main.cpp
)

target_link_libraries(student_app
    PRIVATE student_lib
)

enable_project_warnings(student_app)

# Download GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Create test executable
add_executable(student_tests
    tests/test_student.cpp
)

target_link_libraries(student_tests
    PRIVATE
    student_lib
    GTest::gtest_main
)

enable_project_warnings(student_tests)

include(GoogleTest)

gtest_discover_tests(student_tests)
