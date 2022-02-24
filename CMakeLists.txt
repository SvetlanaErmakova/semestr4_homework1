cmake_minimum_required(VERSION 3.1)

project(homework1)

set(homework1_SRC homework1.cpp CIntN.cpp Autotest.cpp)
set(homework1_HDR CIntN.h Autotest.h)

add_executable(${PROJECT_NAME} ${homework1_SRC} ${homework1_HDR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 /std:c++14")