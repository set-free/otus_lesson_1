# Set min. cmake version
cmake_minimum_required (VERSION 3.12.4) 

# name of project 
project (Lesson_1) 

# Set compile options
set_target_properties(PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)


# Add file to compile (Bin source)
add_executable(Lesson_1 main.cpp)

# Add dir with "spdlog/spdlog.h"
include_directories(spdlog/include)
