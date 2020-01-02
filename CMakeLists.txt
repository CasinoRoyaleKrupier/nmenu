cmake_minimum_required(VERSION 2.8.9)
project (gameTerm)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCES ${SOURCE_DIR}/main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(gameTerm ${SOURCES})
target_link_libraries(gameTerm ${CURSES_LIBRARIES})

install(TARGETS gameTerm RUNTIME DESTINATION bin)