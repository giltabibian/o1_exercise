cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

# set the project name
project(o1_exercise)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
add_subdirectory(${PROJECT_SOURCE_DIR}/apps)
add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
add_subdirectory(${PROJECT_SOURCE_DIR}/third_party)