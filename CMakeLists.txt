cmake_minimum_required(VERSION 3.16)
project(get_next_line C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror -D BUFFER_SIZE=3")

add_executable(test_gnl
        get_next_line.c
        get_next_line_utils.c
        main.c
)