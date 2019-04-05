add_library(sl
    src/alloc.c
    src/io.c
    src/solving.c
)
target_include_directories(sl PUBLIC include)