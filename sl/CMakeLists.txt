add_library(sl
    src/alloc.c
    src/io.c
    src/transform.c
    src/result.c
)
target_include_directories(sl PUBLIC include)