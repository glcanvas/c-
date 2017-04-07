cmake_minimum_required(VERSION 3.6)
project(untitled2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Printer.cpp Printer.h Header.h Calk.cpp Calk.h Checker.cpp Checker.h Commands.cpp)
add_executable(untitled2 ${SOURCE_FILES})