add_library(
    isunique
    src/isunique.cpp
)

target_include_directories(
    isunique
    PUBLIC include
)

set_target_properties(
    isunique
    PROPERTIES CXX_STANDARD 11
)
