cmake_minimum_required(VERSION 3.25.2)

# helper
# include(CMakePrintHelpers)
# cmake_print_variables(PROJECT_SOURCE_DIR)
# cmake_print_variables(c_debug_src)

project(cdbug)

file(GLOB_RECURSE c_debug_src ${PROJECT_SOURCE_DIR} "src/*.h" "src/*.c")

add_executable(main main.c ${c_debug_src})

target_compile_options(main PUBLIC -O2 -Wall)
