cmake_minimum_required(VERSION 3.10)

project(DynamicStrings C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(dynamic_strings
    src/dynamic_strings/string_access.c
    src/dynamic_strings/string_creation.c
    src/dynamic_strings/string_utils.c
    src/dynamic_strings/string_buffer.c
    src/dynamic_strings/string_operation.c
)

target_include_directories(dynamic_strings PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)