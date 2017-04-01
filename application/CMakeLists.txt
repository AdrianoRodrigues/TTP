include_directories(${EO_INCLUDE_DIR})

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(ttp ttp.cpp) 

add_dependencies(ttp lttp)

target_link_libraries(ttp ${PARADISEO_LIBRARIES} lttp)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}")