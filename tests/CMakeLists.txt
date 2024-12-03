cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(amuse_utest_tests tests.cpp)
target_link_libraries(amuse_utest_tests amuse_utest)

add_test(NAME amuse_utest_tests COMMAND amuse_utest_tests)
