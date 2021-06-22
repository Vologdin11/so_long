cmake_minimum_required(VERSION 3.19)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long main.c secondary_functions.c ft_split.c)