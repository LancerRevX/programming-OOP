#include "diagonalmatrix.hpp"

#include <string>

DiagonalMatrix::DiagonalMatrix() {

}

DiagonalMatrix::DiagonalMatrix(std::queue<int>& data_queue) {
    this->read(data_queue);
}

void DiagonalMatrix::read(std::queue<int>& data_queue) {
    auto size {data_queue.front()}; data_queue.pop();
    this->data.resize(size);
    for (size_t i {0}; i < size; i += 1) {
        this->data[i].resize(size);
        this->data[i][i] = data_queue.front(); data_queue.pop();
    }
}

std::string DiagonalMatrix::format() {
    std::string result {"Diagonal matrix:\n"};
    for (auto& row : this->data) {
        for (auto item : row) {
            result += std::to_string(item) + " ";
        }
        result += ";\n";
    }
    return result;
}

std::string DiagonalMatrix::format_with(Matrix* matrix) {
    return matrix->format_with_diagonal_matrix();
}

std::string DiagonalMatrix::format_with_square_matrix() {
    return "Diagonal matrix and square matrix\n";
}

std::string DiagonalMatrix::format_with_diagonal_matrix() {
    return "Two diagonal matrices\n";
}