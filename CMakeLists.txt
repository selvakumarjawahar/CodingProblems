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
        problems/permutations/permutationalgos.h problems/pairsum/sumpair.h problems/pairsum/sumpair.cpp problems/moderateproblems/moderateproblems.h problems/moderateproblems/moderateproblems.cpp problems/rotationalcipher/rotationalcipher.h problems/rotationalcipher/rotationalcipher.cpp problems/contiguosarrayelements/contiguoussubarray.h problems/contiguosarrayelements/contiguoussubarray.cpp problems/linkedlists/linkedlists.h problems/leetfacebooklinkedlist/leetfblinkedlist.h problems/leetfacebooklinkedlist/leetfblinkedlist.cpp problems/leetfbarrays/leetfbarrays.h problems/leetfbarrays/leetfbarrays.cpp problems/treealgos/binarysearchtree.h)

set_target_properties(solutions
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )

add_subdirectory(test)
add_subdirectory(benchmark)
