cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME climage)
project(${PROJECT_NAME})

set(SRC_DIR src)
set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES ${SRC_DIR}/main.cpp src/Image.cpp src/Image.h src/Pixel.cpp src/Pixel.h src/Terminal.cpp src/Terminal.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

