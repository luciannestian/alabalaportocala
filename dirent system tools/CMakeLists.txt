cmake_minimum_required(VERSION 3.6)
project(dirent_system_tools)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp header.h source.cpp)
add_executable(dirent_system_tools ${SOURCE_FILES})