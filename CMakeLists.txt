cmake_minimum_required(VERSION 3.16)
project(calendar)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Tell CMake where to find .ui files
set(CMAKE_AUTOUIC_SEARCH_PATHS resources)

add_executable(calendar-app
    src/main.cpp
    src/mainwindow.cpp
    src/mainwindow.h
    src/calendardata.cpp
    resources/mainwindow.ui
)

target_link_libraries(calendar-app Qt5::Widgets)
