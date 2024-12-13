cmake_minimum_required(VERSION 3.5.0)
project(Task_2 VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Task_2 functions.cpp iofuncs.cpp main.cpp solution.cpp)

#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
