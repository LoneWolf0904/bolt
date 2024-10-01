cmake_minimum_required(VERSION ${CMAKE_VERSION})

project(bolt)

include_directories(
	src
)

add_library(bolt
  src/bolt/Core.cpp src/bolt/Core.h 
)

add_executable(demo
  src/demo/main.cpp
  src/demo/Employee.cpp src/demo/Employee.h
)

target_link_libraries(demo bolt)