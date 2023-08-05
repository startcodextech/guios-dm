cmake_minimum_required(VERSION 3.26)
project(dm)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(dm
        src/main.cpp
        src/main.h
        src/launcher/XorgLauncher.cpp
        src/launcher/XorgLauncher.h
        src/window/Displayer.h
        src/window/Displayer.cpp
        src/window/Colors.h
        src/window/Colors.cpp
        src/window/Manager.h
        src/window/Manager.cpp)
