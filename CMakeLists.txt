cmake_minimum_required(VERSION 3.24)
project(gtk1 C)

set(CMAKE_C_STANDARD 11)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
link_libraries(${GTK_LIBRARIES})

add_executable(gtk1 main.c)
