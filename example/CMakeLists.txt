cmake_minimum_required(VERSION 3.11)

project(ci_test_example LANGUAGES CXX)

find_package(ci_test REQUIRED)

add_executable(ci_test_example example.cpp)

target_link_libraries(ci_test_example ci_test)
