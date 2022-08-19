add_executable(o1_exercise ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(o1_exercise
    PRIVATE services)

include_directories(${PROJECT_SOURCE_DIR})