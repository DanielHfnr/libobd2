cmake_minimum_required(VERSION 3.1)

project(
  LibOBD2
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(obd2)

add_executable(Obd2SampleApp main.cpp)

target_link_libraries(Obd2SampleApp PRIVATE Obd2)

