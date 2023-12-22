cmake_minimum_required(VERSION 3.5)
project(matc C)

if(UNIX)
    add_executable(main main.c matrix.c display_utf8.c fileio.c)
    add_library(matc STATIC matrix.c display_utf8.c fileio.c)
elseif(WIN32)
    add_executable(main main.c matrix.c display.c fileio.c)
    add_library(matc STATIC matrix.c display.c fileio.c)
endif()

set_target_properties(matc PROPERTIES PUBLIC_HEADER "matc.h;matrix.h;display.h;fileio.h")

install(
    TARGETS matc
    LIBRARY lib
    PUBLIC_HEADER DESTINATION include/matc
)
