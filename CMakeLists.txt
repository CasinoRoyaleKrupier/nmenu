cmake_minimum_required(VERSION 2.8.9)
project (nmenu)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES
    ${SOURCE_DIR}/main.c
    ${SOURCE_DIR}/draw.c
    ${SOURCE_DIR}/output.c
    )

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(nmenu ${SOURCES})
target_link_libraries(nmenu ${CURSES_LIBRARIES})

install(TARGETS nmenu RUNTIME DESTINATION bin)