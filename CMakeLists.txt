cmake_minimum_required(VERSION 3.10)

project(LSystem)
set (CMAKE_CXX_STANDARD 14)

find_package(wxWidgets CONFIG REQUIRED)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
add_executable(lsystem main.cpp Turtle.cpp LSystem.cpp)

target_link_libraries(lsystem PRIVATE wx::core wx::base)
