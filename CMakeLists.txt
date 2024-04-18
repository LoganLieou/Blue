cmake_minimum_required(VERSION 3.28)
project(Blue)

set(CMAKE_CXX_STANDARD 17)

add_executable(Blue src/Main.cpp
        src/Lexer.hpp
        src/Lexer.cpp
        src/Parser.hpp
        src/Parser.cpp
        src/AST.hpp
        src/AST.cpp)
