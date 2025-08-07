cmake_minimum_required(VERSION 3.15)
project(raylib-visuals LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("/opt/raylib/include")

add_library(main MODULE main.c)


