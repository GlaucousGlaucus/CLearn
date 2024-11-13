cmake_minimum_required(VERSION 3.29)
project(CLearn C)

set(CMAKE_C_STANDARD 11)

add_executable(CLearn
        old/version.c
    old/main.c
    old/next_step.c
        DSA/LinkedLists/basics.c
        DSA/LinkedLists/stack_impl.c
        DSA/LinkedLists/queue_impl.c
        "DSA/Trees And Graphs/binary_tree.c")
