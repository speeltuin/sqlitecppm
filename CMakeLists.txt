cmake_minimum_required(VERSION 3.28)
project(hello VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

add_library(speech)

target_sources(
    speech
    PUBLIC FILE_SET CXX_MODULES
        FILES
            speech.cppm
            speech_english.cppm
            speech_spanish.cppm
)

set_target_properties(
    speech
    PROPERTIES
        VERSION ${hello_VERSION}
        SOVERSION ${hello_VERSION}
        WINDOWS_EXPORT_ALL_SYMBOLS ON
)

add_executable(hello hello.cpp)

set_target_properties(
    hello
    PROPERTIES
        INSTALL_RPATH "$ORIGIN/../lib"
)

target_link_libraries(hello speech)

add_test(NAME hello COMMAND hello)

install(
    TARGETS
        speech
        hello
    FILE_SET CXX_MODULES
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)
