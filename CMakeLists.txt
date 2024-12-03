cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(amuse_utest STATIC src/utest.cpp)
target_include_directories(amuse_utest PUBLIC include)

if (MSVC)
    target_compile_options(amuse_utest PRIVATE /W4 /WX)
else()
    target_compile_options(amuse_utest PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

enable_testing()
add_subdirectory(tests)
