
find_package(GTest REQUIRED)

add_library(Obd2 STATIC src/obd2/connection_handler.cpp)

target_include_directories(Obd2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
include(GoogleTest)

add_executable(obd2_unit_tests test/obd2/connection_handler.test.cpp)

target_link_libraries(obd2_unit_tests PRIVATE GTest::gtest_main Obd2)