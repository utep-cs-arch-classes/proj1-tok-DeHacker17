cmake_minimum_required(VERSION 3.17)
project(proj1_tok_DeHacker17 C)

set(CMAKE_C_STANDARD 11)

include_directories(sortArgDemo)
include_directories(src)

add_executable(proj1_tok_DeHacker17
        sortArgDemo/bst.c
        sortArgDemo/bst.h
        sortArgDemo/sortargs.c
        src/history.h
        src/tester.c
        src/tokenizer.h)
