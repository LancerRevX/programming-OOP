#include <gtest/gtest.h>

#include "matrix.hpp"
#include "squarematrix.hpp"
#include "diagonalmatrix.hpp"
#include "lower_triangular_matrix.hpp"

using namespace std;

TEST(Matrix, create) {
    Matrix* matrix;

    queue data_queue_square_matrix {deque({
        1, 
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1
    })};
    matrix = Matrix::create(data_queue_square_matrix);
    ASSERT_TRUE(dynamic_cast<SquareMatrix*>(matrix));

    queue data_queue_diagonal_matrix {deque({
        2, 
        3, 
        1, 2, 3,
        1
    })};
    matrix = Matrix::create(data_queue_diagonal_matrix);
    ASSERT_TRUE(dynamic_cast<DiagonalMatrix*>(matrix));
    
    queue data_queue_lower_triangular_matrix {deque({
        3, 
        3, 
        1, 2, 3, 4, 5, 6,
        1
    })};
    matrix = Matrix::create(data_queue_lower_triangular_matrix);
    ASSERT_TRUE(dynamic_cast<LowerTriangularMatrix*>(matrix));
}

TEST(Matrix, get_sum) {
    queue data_queue {deque({
        1, 
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1
    })};
    auto* matrix {Matrix::create(data_queue)};
    ASSERT_EQ(matrix->get_sum(), 1+2+3+4+5+6+7+8+9);
}