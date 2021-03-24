cmake_minimum_required(VERSION 3.0)
project("Movie Bench")
include_directories(include)
add_executable(app 
    src/main.cpp
    src/app.cpp
    src/movie.cpp
    src/command.cpp
)