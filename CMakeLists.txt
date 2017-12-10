cmake_minimum_required(VERSION 3.5.1)
project(lab2_cpp_calculator)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp mainwindow.ui mainwindow.cpp mainwindow.h)

#set(Qt5Core_DIR "/opt/Qt/5.9.3/gcc_64/lib/cmake/Qt5Core/")
#set(Qt5Widgets_DIR "/opt/Qt/5.9.3/gcc_64/lib/cmake/Qt5Widgets/")

SET(CMAKE_AUTOUIC ON)

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(
        ${CMAKE_CURRENT_BINARY_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(lab2_cpp_calculator ${SOURCE_FILES})



find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )


qt5_use_modules( lab2_cpp_calculator Core Widgets Gui )
