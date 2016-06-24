cmake_minimum_required(VERSION 3.5)
project(airbnpeek)

set(USER_HOME_DIRECTORY "$ENV{HOME}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

include_directories(include)

set(BOOST_ROOT "${USER_HOME_DIRECTORY}/code/devel/lib/boost")
find_package(Boost 1.61 REQUIRED COMPONENTS program_options system)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES src/main.cpp src/error.cpp src/network.cpp src/network_ipv4.cpp src/network_ipv6.cpp)
add_executable(airbnpeek ${SOURCE_FILES})
target_link_libraries(airbnpeek ${Boost_LIBRARIES})
