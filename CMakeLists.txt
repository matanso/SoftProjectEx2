cmake_minimum_required(VERSION 3.5)
project(Ex_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g - Werror -std=c99")

set(SOURCE_FILES
#    unit_tests/sp_point_unit_test.c
#    unit_tests/unit_test_util.h
    makefile
    SPBPriorityQueue.h
    SPBPriorityQueueTest.make
    SPPoint.h
    SPPointTest.make SPPoint.c SPBPriorityQueue.c main.c main_aux.h main_aux.c
#        unit_tests/sp_bpqueue_unit_tests.c
        )

add_executable(Ex_2 ${SOURCE_FILES})

set_property(TARGET Ex_2 PROPERTY C_STANDARD 99)