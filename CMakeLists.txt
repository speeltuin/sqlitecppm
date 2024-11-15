# SPDX-License-Identifier: MIT
# Copyright (c) 2024 AlgorIT Software Consultancy, the Netherlands

cmake_minimum_required(VERSION 3.28)

project(
    SQLitecppm
    VERSION 0.1.0
    DESCRIPTION "SQLite C++ Module"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#include(CodeCoverage)
#include(FetchContent)
include(GNUInstallDirs)
include(CTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_library(sqlitecppm)
add_library(SQLitecppm::sqlitecppm
    ALIAS sqlitecppm
)

set_target_properties(
    sqlitecppm
    PROPERTIES
        VERSION ${SQLitecppm_VERSION}
        SOVERSION ${SQLitecppm_VERSION}
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_sources(
    sqlitecppm
    PUBLIC FILE_SET CXX_MODULES
        BASE_DIRS
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
        FILES
            "${CMAKE_CURRENT_SOURCE_DIR}/include/sqlite/sqlite.capi3.cppm"
)

install(
    TARGETS
        sqlitecppm
    FILE_SET CXX_MODULES
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
