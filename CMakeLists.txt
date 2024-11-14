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

include(CodeCoverage)
include(FetchContent)
include(GNUInstallDirs)
include(CTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

option(SQLITE_BUILD_SHELL "" OFF)
FetchContent_Declare(
    sqlite-amalgamation
    GIT_REPOSITORY "https://github.com/algoritnl/sqlite-amalgamation-cmake-buildsystem.git"
    GIT_TAG main
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/extern/sqlite-amalgamation
)
set(SQLITE_DQS "0" CACHE INTERNAL "")
set(SQLITE_THREADSAFE "2" CACHE INTERNAL "")
set(SQLITE_DEFAULT_MEMSTATUS "0" CACHE INTERNAL "")
set(SQLITE_DEFAULT_WAL_SYNCHRONOUS "1" CACHE INTERNAL "")
set(SQLITE_MAX_EXPR_DEPTH "0" CACHE INTERNAL "")
set(SQLITE_LIKE_DOESNT_MATCH_BLOBS ON INTERNAL "")
set(SQLITE_ENABLE_API_ARMOR ON INTERNAL "")
set(SQLITE_ENABLE_COLUMN_METADATA ON INTERNAL "")
set(SQLITE_OMIT_SHARED_CACHE ON INTERNAL "")
set(SQLITE_USE_ALLOCA ON INTERNAL "")
FetchContent_MakeAvailable(sqlite-amalgamation)

add_library(sqlitecppm)
add_library(
    SQLitecppm::sqlitecppm
    ALIAS sqlitecppm
)

target_sources(
    sqlitecppm
    PUBLIC FILE_SET CXX_MODULES
        BASE_DIRS
            "${CMAKE_CURRENT_SOURCE_DIR}/include"
        FILES
            "${CMAKE_CURRENT_SOURCE_DIR}/include/sqlite/sqlite.capi3.cppm"
)

target_include_directories(
    sqlitecppm
    PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    PUBLIC "$<INSTALL_INTERFACE:include>"
)

target_compile_features(
    sqlitecppm
    PUBLIC cxx_std_20
)

target_link_libraries(
    sqlitecppm
    PUBLIC SQLite::SQLite3
)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()

install(TARGETS sqlitecppm
    EXPORT SQLitecppmTargets
    FILE_SET CXX_MODULES DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
install(EXPORT SQLitecppmTargets
    FILE SQLitecppmTargets.cmake
    NAMESPACE SQLitecppm::
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/SQLitecppm")

export(EXPORT SQLitecppmTargets
    NAMESPACE SQLitecppm::
    FILE "${CMAKE_CURRENT_BINARY_DIR}/SQLitecppmTargets.cmake")

include(CMakePackageConfigHelpers)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SQLitecppmConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/SQLitecppmConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/SQLitecppm"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SQLitecppmConfigVersion.cmake"
    COMPATIBILITY AnyNewerVersion)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/SQLitecppmConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SQLitecppmConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/SQLitecppm")

include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_VERSION_MAJOR "${SQLitecppm_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${SQLitecppm_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${SQLitecppm_VERSION_PATCH}")
include(CPack)
