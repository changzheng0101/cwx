cmake_minimum_required(VERSION 3.17)
project(cwx C)

set(CMAKE_C_STANDARD 99)

add_executable(cwx main.c chunk.c debug.c memory.c
        value.h
        value.c
        vm.h
        vm.c
        compiler.h
        compiler.c
        scanner.h
        scanner.c
        object.h
        object.c
        table.h
        table.c)
