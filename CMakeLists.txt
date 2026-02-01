cmake_minimum_required(VERSION 3.16)

project(auto_util
    VERSION 0.0.1
    LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(auto_util
    src/main.c
    src/modulos.c
)

target_include_directories(auto_util PRIVATE
    includes
    funçoes
)

