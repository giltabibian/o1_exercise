add_executable(unit_tests ${CMAKE_CURRENT_SOURCE_DIR}/unit_test.cpp)

target_link_libraries(unit_tests
    PRIVATE services catch)

include_directories(${PROJECT_SOURCE_DIR}/third_party/catch)

include_directories(${PROJECT_SOURCE_DIR})