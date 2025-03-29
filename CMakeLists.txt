cmake_minimum_required(VERSION 3.16)
project(Geo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM gtkmm-4.0 REQUIRED)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(Geo 
    src/main.cpp
    src/gui/MainWindow.cpp
    src/gui/Renderer.cpp
    src/emulator/CPU.cpp
    src/emulator/GPU.cpp
    src/emulator/Memory.cpp
    src/emulator/Input.cpp
    src/emulator/Audio.cpp
    src/emulator/DVD.cpp
    src/emulator/Emulator.cpp
    src/utils/Logger.cpp
    src/utils/Config.cpp
)

target_link_libraries(Geo ${GTKMM_LIBRARIES})
