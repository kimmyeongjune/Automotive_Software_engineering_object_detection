cmake_minimum_required(VERSION 3.10)
project(FaceDetection)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)

add_executable(FaceDetection src/main.cpp)

target_link_libraries(FaceDetection ${OpenCV_LIBS})