cmake_minimum_required(VERSION 2.8.3)
project(pong)

if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set (CMAKE_CXX_FLAGS "--std=gnu++11 ${CMAKE_CXX_FLAGS}")
    endif ()
else ()
    set (CMAKE_CXX_STANDARD 11)
endif ()

set(Qt5_DIR "/home/drewlatwas/Qt/5.8/gcc_64/lib/cmake/Qt5")# FIXME: replace this with the installation path of your QT
set(CMAKE_AUTOMOC ON)
set(QT_QMAKE_EXECUTABLE "/home/drewlatwas/Qt/5.8/gcc_64/bin/qmake")# FIXME: replace this with the installation path of your QT
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Boost REQUIRED COMPONENTS system)

find_package(Qt5 5.8 REQUIRED COMPONENTS Core Gui Widgets REQUIRED)
add_definitions(${QT_DEFINITIONS})
include_directories({QT_LIBRARY_DIRS})
add_definitions(${QT_DEFINITIONS})

# Specify header files
set(HDRS
    ./src/MasterGui.hpp
)

# Specify source files
set(SRCS
    ./src/MasterGui.cpp
    ./src/main.cpp
)


# Build & link
add_executable(pong ${HDRS} ${SRCS})
qt5_use_modules(pong Core Gui Widgets)
