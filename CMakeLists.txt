cmake_minimum_required(VERSION 3.12)

set( CMAKE_VERBOSE_MAKEFILE off )

project(solutions
        VERSION 0.1
        LANGUAGES CXX C
        )

add_library( solutions STATIC
        problems/factorial/factorial.h
        problems/factorial/factorial.cpp
        problems/isunique/isunique.h
        problems/isunique/isunique.cpp
        )

set_target_properties(solutions
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

add_subdirectory(test)
