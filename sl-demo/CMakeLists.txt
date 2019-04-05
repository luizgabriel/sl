add_executable(demo_gauss src/gauss.c)
target_link_libraries(demo_gauss PUBLIC sl)

add_executable(demo_jordan src/jordan.c)
target_link_libraries(demo_jordan PUBLIC sl)

add_executable(demo_briot_ruffini src/briot_ruffini.c)
target_link_libraries(demo_briot_ruffini PUBLIC sl)