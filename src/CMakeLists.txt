file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/services/*.cpp)
add_library(services ${sources})


# add the executable
add_executable(o1_exercise ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(o1_exercise
    PRIVATE services)