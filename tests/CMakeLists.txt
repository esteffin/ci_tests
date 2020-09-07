set(SRCS "test.cpp")

# Adding the test binary target
add_executable(ci_test_test ${SRCS})

target_link_libraries(ci_test_test ci_test)

add_test(NAME "ci_test_test" COMMAND ./ci_test_test)
