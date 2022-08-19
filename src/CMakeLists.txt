file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp)
add_library(services ${sources})