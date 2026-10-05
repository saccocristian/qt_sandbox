cmake_minimum_required(VERSION 3.16)
project(qt_sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_executable(${PROJECT_NAME}
    main.cpp
    utils.h
    main_window.h
    main_window.cpp
    main_window.ui
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt5::Widgets
)
