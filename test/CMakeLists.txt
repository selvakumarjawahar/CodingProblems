add_executable(runtests
        src/main.cpp
        src/isunique_test.cpp
        src/permutationalgos_test.cpp
        src/sumpair_test.cpp
        src/moderateproblems_test.cpp
        src/rotationalcipher_test.cpp
        src/contiguoussubarray_test.cpp
        )

set_target_properties(runtests
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

target_include_directories(runtests
        PRIVATE ${CMAKE_SOURCE_DIR}/tests/
        PRIVATE ${CMAKE_SOURCE_DIR}/problems
        )

target_link_libraries(runtests
        PRIVATE solutions
        )

target_include_directories(runtests
            PRIVATE ${CMAKE_SOURCE_DIR}/test
            )
