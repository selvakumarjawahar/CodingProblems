add_library(factorial
    src/factorial.cpp
)

target_include_directories(
    factorial
    PUBLIC include
)

set_target_properties(
    factorial
    PROPERTIES CXX_STANDARD 11
)
