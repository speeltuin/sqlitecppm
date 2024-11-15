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

target_sources(
    sqlitecppm
    PUBLIC FILE_SET CXX_MODULES
        BASE_DIRS
            "${CMAKE_CURRENT_SOURCE_DIR}"
        FILES
            "${CMAKE_CURRENT_SOURCE_DIR}/speech.cppm"
            "${CMAKE_CURRENT_SOURCE_DIR}/speech_english.cppm"
            "${CMAKE_CURRENT_SOURCE_DIR}/speech_spanish.cppm"
)

set_target_properties(
    sqlitecppm
    PROPERTIES
        VERSION ${hello_VERSION}
        SOVERSION ${hello_VERSION}
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

add_executable(sqlitecppm_test hello.cpp)

set_target_properties(
    sqlitecppm_test
    PROPERTIES
        INSTALL_RPATH "$ORIGIN/../lib"
)

target_link_libraries(sqlitecppm_test sqlitecppm)

add_test(NAME sqlitecppm_test COMMAND sqlitecppm_test)

install(
    TARGETS
        sqlitecppm
        sqlitecppm_test
    FILE_SET CXX_MODULES
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
