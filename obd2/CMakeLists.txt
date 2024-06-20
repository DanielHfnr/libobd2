

add_library(Obd2 STATIC src/obd2/connection_handler.cpp)

target_include_directories(Obd2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
