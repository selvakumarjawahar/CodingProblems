cmake_minimum_required(VERSION 3.12)

set( CMAKE_VERBOSE_MAKEFILE off )

project(bingo-core
        VERSION 0.1
        LANGUAGES CXX C
        )

set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

add_library( bingo-core STATIC
        src/core.cpp
        src/core.h
        src/bingo-mdbx/mdbxdb.h
        src/bingo-mdbx/mdbxerr.h
        src/bingo-mdbx/mdbxdb.cpp
        src/bingo-gen/fsmactions.h
        src/bingo-gen/fsmevents.h
        src/bingo-gen/fsmstates.h
        src/bingo-gen/fsmtransitiontable.h
        src/bingo-gen/fsmtransitiontable.cpp
        thirdparty/hinnat-date/date.h
        src/bingo-levenshtein_distance/levenshtein.h
        src/bingo-levenshtein_distance/levenshtein.cpp
        )

set_target_properties(bingo-core
        PROPERTIES CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
        )


find_package(
        Boost
        1.71.0
        EXACT
        REQUIRED
        COMPONENTS system thread regex
)

add_subdirectory(thirdparty/libmdbx
        thirdparty/libmdbx/build
        )

add_subdirectory(thirdparty/fmt)

if(Boost_FOUND)
    target_include_directories(bingo-core
            PRIVATE ${Boost_INCLUDE_DIRS}
            PRIVATE thirdparty
            )
    target_link_libraries(bingo-core
            PRIVATE ${Boost_LIBRARIES}
            PRIVATE -lpthread
            mdbx-static
            fmt::fmt
            )
endif()

add_subdirectory(tests/unit_tests)
