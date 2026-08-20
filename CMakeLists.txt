cmake_minimum_required(VERSION 3.20)
project(leetcode_solutions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Every LeetCode submission is compiled independently. They intentionally do
# not include main(), because LeetCode provides its own test harness.
file(GLOB_RECURSE SOLUTION_SOURCES CONFIGURE_DEPENDS "*.cpp")

foreach(source_file IN LISTS SOLUTION_SOURCES)
    file(RELATIVE_PATH relative_path "${CMAKE_CURRENT_SOURCE_DIR}" "${source_file}")
    string(REPLACE "/" "_" target_name "${relative_path}")
    string(REPLACE ".cpp" "" target_name "${target_name}")
    add_library("${target_name}" OBJECT "${source_file}")
endforeach()
