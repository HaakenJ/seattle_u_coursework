cmake_minimum_required(VERSION 3.17)
project(homework)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(p3)

add_executable(homework
        p3/Book.cpp
        p3/Book.h
        p3/Driver.cpp
        p3/Driver.h
        p3/main.cpp
        p3/Member.cpp
        p3/Member.h
        p3/Rating.cpp
        p3/Rating.h)
