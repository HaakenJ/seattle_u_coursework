cmake_minimum_required(VERSION 3.17)
project(p3)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        ./*.h
        ./*.cpp
        )

set(PROJECT_SOURCES
        Rating.cpp
        Book.cpp
        Member.cpp
        )

set(PROJECT_HEADERS
        Rating.h
        Book.h
        Member.h
        )

add_executable(p3 main.cpp Driver.cpp Driver.h  ${SOURCES})