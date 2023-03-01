cmake_minimum_required(VERSION 3.10)
project(assignment2)
set(CMAKE_CXX_STANDARD 11)

include_directories(./)
file(COPY words.json DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY madLibs1.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(main main.cpp MadLibsController.cpp MadlibUserWordProvider.cpp MadlibAutoWordProvider.cpp)
