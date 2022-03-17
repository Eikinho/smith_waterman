cmake_minimum_required(VERSION 3.10)
project(SmithWaterman  VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3 -Wall")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")


add_library(
	aux
	libs/aux/aux.cpp
	)

target_include_directories(aux PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH "../bin")
add_executable(exe src/smith_waterman.cpp)

target_link_libraries(exe PRIVATE aux)