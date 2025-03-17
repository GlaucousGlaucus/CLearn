cmake_minimum_required(VERSION 3.29)
project(CLearn C)

set(CMAKE_C_STANDARD 11)

add_executable(CLearn
        old/version.c
    old/main.c
    old/next_step.c
        DSA/LinkedLists/basics.c
        DSA/LinkedLists/circular.c
        DSA/LinkedLists/doubly.c
        DSA/LinkedLists/stacks.c
        DSA/LinkedLists/queue.c
        DSA/LinkedLists/poly.c
        DSA/Trees/basics.c
        NM/bisection_method.c
        NM/regular_falsie.c
        NM/gauss_jordarn.c
        "NM/newton fb.c"
)
