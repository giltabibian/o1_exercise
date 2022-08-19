file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/catch/*.h)
add_library(catch ${sources})

set_target_properties(catch PROPERTIES LINKER_LANGUAGE CXX)