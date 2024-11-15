# SPDX-License-Identifier: MIT
# Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

option(BUILD_GMOCK "" OFF)
option(INSTALL_GTEST "" OFF)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY "https://github.com/google/googletest.git"
    GIT_TAG main
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/extern/googletest
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(
    sqlitecppm_test
)

set_target_properties(
    sqlitecppm_test
    PROPERTIES
        INSTALL_RPATH "$ORIGIN/../lib"
)

target_sources(
    sqlitecppm_test
    PRIVATE
        sqlite.capi3_test.cpp
)

target_link_libraries(
    sqlitecppm_test
    PRIVATE
        SQLitecppm::sqlitecppm
        GTest::gtest_main
)

add_test(NAME sqlitecppm_test COMMAND sqlitecppm_test)

if(WIN32)
    set_tests_properties(
        sqlitecppm_test
        PROPERTIES
            ENVIRONMENT
                "PATH=$<SHELL_PATH:$<TARGET_FILE_DIR:GTest::gtest_main>>$<SEMICOLON>$ENV{PATH}"
    )
endif()
