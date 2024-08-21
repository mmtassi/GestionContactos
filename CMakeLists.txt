cmake_minimum_required(VERSION 3.29)
project(GestionContactos C)

set(CMAKE_C_STANDARD 23)

add_executable(GestionContactos main.c
        header.c
        header.h)
