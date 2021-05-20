cmake_minimum_required(VERSION 3.19)

set(CMAKE_CXX_STANDARD 17)

project(programming-OOP-tests)

include_directories(../)
add_executable(
    programming-OOP-tests 
    main.cpp
    matrix.cpp
    square_matrix.cpp
    diagonal_matrix.cpp
    lower_triangular_matrix.cpp
    matrix_container.cpp
    ../matrix.cpp 
    ../squarematrix.cpp 
    ../diagonalmatrix.cpp 
    ../lower_triangular_matrix.cpp
)

target_link_libraries(programming-OOP-tests gtest)