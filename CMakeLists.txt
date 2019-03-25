# Set min. cmake version
cmake_minimum_required (VERSION 3.13) 

# name of project 
project (Lesson_1) 

# Add file to compile (Bin source)
add_executable(Lesson_1 main.cpp)

# Add dir with "spdlog/spdlog.h"
include_directories(spdlog/include)
