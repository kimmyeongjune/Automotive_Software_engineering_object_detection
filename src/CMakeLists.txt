cmake_minimum_required(VERSION 3.10)
project(OpenCV_Project)

# C++ 표준 설정
set(CMAKE_CXX_STANDARD 11)

# OpenCV 라이브러리 찾기
find_package(OpenCV REQUIRED)

# 실행 파일 생성
add_executable(main src/main.cpp)

# OpenCV 라이브러리 링크
target_link_libraries(main ${OpenCV_LIBS})