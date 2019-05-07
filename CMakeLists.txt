cmake_minimum_required(VERSION 3.14)
project(untitled1)

set(CMAKE_PREFIX_PATH  "D:/Qt/5.12.3/mingw73_64")
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui)

set(CMAKE_CXX_STANDARD 17)



add_executable(untitled1 main.cpp mainwindow.cpp mainwindow.h)