cmake_minimum_required(VERSION 3.8)

project(
    codingproblems
    VERSION 1.1
    LANGUAGES C CXX     
)

add_executable(
    runproblem
    main.cpp
)

target_link_libraries(
    runproblem
    PRIVATE factorial isunique
)

set_target_properties(
    runproblem
    PROPERTIES CXX_STANDARD 11
)

add_subdirectory(
    Problems
)