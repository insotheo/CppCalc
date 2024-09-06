cmake_minimum_required(VERSION 3.10)

project(ConsoleCalc VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES
src/*.cpp
src/*/*.cpp
)

file(GLOB HEADERS
src/*.hpp
src/*/*.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})