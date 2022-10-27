cmake_minimum_required(VERSION 3.23)
project(Module_7)

set(CMAKE_CXX_STANDARD 14)

add_executable(Module_7_All Test1.cpp Test2.cpp "JNumberHashTest.cpp" Test4.cpp)
add_executable(Module7_Test_1 Test1.cpp)
add_executable(Module7_Test_2 Test2.cpp)
add_executable(Module7_Test_3 "JNumberHashTest.cpp")
add_executable(Module7_Test_4 Test4.cpp)


