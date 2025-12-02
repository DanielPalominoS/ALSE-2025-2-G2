cmake_minimum_required(VERSION 3.10)
project(QtLoginInterface LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(QtLoginInterface
    main.cpp
    MainWindow.cpp
    MainWindow.h
)

target_link_libraries(QtLoginInterface PRIVATE Qt5::Widgets)
