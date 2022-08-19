file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp)
add_library(sevices ${sources})


# add the executable
add_executable(o1_exercise main.cpp)