#include "matrix.hpp"
#include "squarematrix.hpp"
#include "diagonalmatrix.hpp"

Matrix* Matrix::create(std::queue<int>& data_queue) {
    auto type {data_queue.front()}; data_queue.pop();
    switch (type) {
        case Type::SQUARE:
            return new SquareMatrix(data_queue);
            break;
        case Type::DIAGONAL:
            return new DiagonalMatrix(data_queue);
            break;
        default:
            throw std::runtime_error("Invalid matrix type!");
    }
}