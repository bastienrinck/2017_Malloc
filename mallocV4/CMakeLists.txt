cmake_minimum_required(VERSION 3.9)
project(mallocV4)

set(CMAKE_CXX_STANDARD 11)

add_executable(mallocV4
        calloc.c
        free.c
        malloc.c
        malloc.h
        pthread.c
        realloc.c
        show_alloc_mem.c)
