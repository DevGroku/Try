cmake_minimum_required(VERSION 3.14)
project(untitled1)

add_executable(learn learn.cpp)


set(CMAKE_PREFIX_PATH  "D:/Qt/5.12.3/mingw73_64")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp mainwindow.cpp mainwindow.h)
target_link_libraries(untitled1 Qt5::Core Qt5::Widgets)

# deploy // copy Qt dlls to executable directory
get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
get_filename_component(QT5_WINDEPLOYQT_EXECUTABLE ${QT5_QMAKE_EXECUTABLE} PATH)
set(QT5_WINDEPLOYQT_EXECUTABLE "${QT5_WINDEPLOYQT_EXECUTABLE}/windeployqt.exe")
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${QT5_WINDEPLOYQT_EXECUTABLE} --qmldir ${CMAKE_SOURCE_DIR} $<TARGET_FILE_DIR:${PROJECT_NAME}> DEPENDS untitled1)
