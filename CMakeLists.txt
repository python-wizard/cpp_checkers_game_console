cmake_minimum_required(VERSION 3.19)
project(checkers_console)

set(CMAKE_CXX_STANDARD 20)

add_executable(checkers_console main.cpp sources/board.cpp include/board.h sources/man.cpp include/man.h sources/king.cpp include/king.h sources/piece.cpp include/piece.h sources/other.cpp include/other.h)