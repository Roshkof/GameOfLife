cmake_minimum_required(VERSION 3.12)
project(ChangeMyName CXX)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# Put Your .cpp files in line below
	add_library(GameOfLife_core src/GameOfLife.cpp)
	target_include_directories(GameOfLife_core PUBLIC include)

	add_executable(GameOfLife src/main.cpp)
	target_link_libraries(GameOfLife GameOfLife_core)
