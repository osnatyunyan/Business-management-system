cmake_minimum_required(VERSION 3.19)
project(assigment7 C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -ansi -Wall -pedantic-errors -lm -D TESTING")

add_executable(Assigment7 Matrix.c main.c Testing.c Testing.h Menu.c Menu.h Client.c Client.h Supplier.h Supplier.c Car.c Car.h Given.c Given.h Check.c Check.h  Matam.c Matam.h Tree.c Tree.h Matrix.c)
