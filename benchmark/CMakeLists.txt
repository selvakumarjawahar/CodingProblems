add_executable(runbenchmark main.cpp benchmark_heap_permutation.cpp)

set_target_properties(runbenchmark
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

target_include_directories(runbenchmark
        PRIVATE ${CMAKE_SOURCE_DIR}/benchmark
        PRIVATE ${CMAKE_SOURCE_DIR}/problems
        )

target_link_libraries(runbenchmark
        PRIVATE solutions
        )
