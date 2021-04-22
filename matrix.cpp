#include "matrix.hpp"
#include "squarematrix.hpp"
#include "diagonalmatrix.hpp"
#include "lower_triangular_matrix.hpp"

#include <string>

Matrix* Matrix::create(std::queue<int>& data_queue) {
    auto type {data_queue.front()}; data_queue.pop();
    switch (type) {
        case Type::SQUARE:
            return new SquareMatrix(data_queue);
        case Type::DIAGONAL:
            return new DiagonalMatrix(data_queue);
            break;
        case Type::LOWER_TRIANGULAR:
            return new LowerTriangularMatrix(data_queue);
            break;
        default:
            throw std::runtime_error("Invalid matrix type!");
    }
}

int Matrix::get_sum() {
    int result = 0;
    for (auto& row : this->data) {
        for (auto item : row) {
            result += item;
        }
    }
    return result;
}
