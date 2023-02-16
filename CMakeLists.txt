cmake_minimum_required(VERSION 3.25.2)

project(cdbug)

add_executable(main main.c src/utils/str_pointer.c src/utils/str_pointer.h src/utils/linked_list.h src/utils/linked_list.c)

target_compile_options(main PUBLIC -O2 -Wall)
