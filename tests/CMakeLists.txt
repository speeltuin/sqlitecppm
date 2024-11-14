# SPDX-License-Identifier: MIT
# Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

option(INSTALL_GTEST "" OFF)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG main
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/extern/googletest
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(sqlitecppm_test)

target_sources(
    sqlitecppm_test
    PUBLIC sqlite.capi3_test.cpp
)

#target_compile_options(
#    sqlitecppm_test
#    PUBLIC -Wall -Wextra -Wpedantic
#)

target_link_libraries(
    sqlitecppm_test
    PUBLIC SQLitecppm::sqlitecppm
    PUBLIC GTest::gtest_main
)

gtest_discover_tests(sqlitecppm_test)
