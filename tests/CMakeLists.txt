# SPDX-License-Identifier: MIT
# Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

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
)

add_test(
    NAME sqlitecppm_test
    COMMAND sqlitecppm_test
)
