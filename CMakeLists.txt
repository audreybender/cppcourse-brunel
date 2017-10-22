project(Neurone) 

set( CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")
add_executable (Neurone neurone.cpp main.cpp)


enable_testing()
add_-subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable (testNeurone neurone.cpp testNeurone.cpp)
target_link_libraries(testNeurone gtest gtest_main)
add_test(testNeurone testNeurone)
