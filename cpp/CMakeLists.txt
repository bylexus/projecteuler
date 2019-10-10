cmake_minimum_required(VERSION 3.0.0)
project(projecteuler VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")

add_library(math STATIC lib/math.cpp)
target_include_directories(math PRIVATE .)

add_executable(projecteuler main.cpp)
target_link_libraries(projecteuler math)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
