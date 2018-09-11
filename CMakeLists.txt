cmake_minimum_required(VERSION 3.8)

project(
    codingproblems
    VERSION 1.0
    LANGUAGES C CXX     
)

add_executable(
    runproblem
    main.cpp
)

target_link_libraries(
    runproblem
    PRIVATE factorial
)

set_target_properties(
    runproblem
    PROPERTIES CXX_STANDARD 11
)

add_subdirectory(
    Problems
)