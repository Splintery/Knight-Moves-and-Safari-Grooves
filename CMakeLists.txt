cmake_minimum_required(VERSION 3.24)
project(knight_moves_and_safari_grooves)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "/usr/include/SFML")

find_package(SFML 2.5.1 COMPONENTS graphics window system REQUIRED)

add_executable(knight_moves_and_safari_grooves src/main.cpp)

target_link_libraries(knight_moves_and_safari_grooves sfml-graphics sfml-window sfml-system)