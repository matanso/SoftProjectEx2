cmake_minimum_required(VERSION 3.5)
project(Ex_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g - Werror -std=c99")

set(SOURCE_FILES
        unit_tests/unit_test_util.h
        SPBPriorityQueue.h
        SPBPriorityQueue.c
        SPPoint.h
        SPPoint.c
        main_aux.h
        main_aux.c)

add_executable(Ex_2 ${SOURCE_FILES} main.c)
add_executable(PointTest ${SOURCE_FILES} unit_tests/sp_point_unit_test.c)
add_executable(QueueTest ${SOURCE_FILES} unit_tests/sp_bpqueue_unit_tests.c)

set_property(TARGET Ex_2 PROPERTY C_STANDARD 99)
set_property(TARGET PointTest PROPERTY C_STANDARD 99)
set_property(TARGET QueueTest PROPERTY C_STANDARD 99)