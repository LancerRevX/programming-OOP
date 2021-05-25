#include "squarematrix.hpp"

#include <string>

SquareMatrix::SquareMatrix() {

}

SquareMatrix::SquareMatrix(std::queue<int>& data_queue) {
    this->read(data_queue);
}

void SquareMatrix::read(std::queue<int>& data_queue) {
    auto size {data_queue.front()}; data_queue.pop();
    this->data.resize(size);
    for (auto& row : this->data) {
        row.resize(size);
        for (size_t i {0}; i < size; i += 1) {
            row[i] = data_queue.front(); data_queue.pop();
        }
    }
}

std::string SquareMatrix::format() {
    std::string result = "Square matrix:\n";
    for (auto& row : this->data) {
        for (auto item : row) {
            result += std::to_string(item) + " ";
        }
        result += ";\n";
    }
    return result;
}

std::string SquareMatrix::format_with(Matrix* right) {
    return right->format_with_square_matrix();
}

std::string SquareMatrix::format_with_square_matrix() {
    return "Two square matrices\n";
}

std::string SquareMatrix::format_with_diagonal_matrix() {
    return "Square matrix and diagonal matrix\n";
}
