# ============================================================================
# C O P Y R I G H T
# ----------------------------------------------------------------------------
# \copyright (C) 2024 Daniel Hafner
# ============================================================================

cmake_minimum_required(VERSION 3.1)

project(
  LibOBD2
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option( GCOVR "Use gcovr" OFF )

if (GCOVR)
    set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} --coverage")
endif(GCOVR)

add_subdirectory(obd2)

add_executable(Obd2SampleApp main.cpp)

target_link_libraries(Obd2SampleApp PRIVATE Obd2)

