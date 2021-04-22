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

std::string DiagonalMatrix::format(bool filter) {
    if (filter) {
        return std::string();
    }
    std::string result {"Diagonal matrix:\n"};
    for (auto& row : this->data) {
        for (auto item : row) {
            result += std::to_string(item) + " ";
        }
        result += ";\n";
    }
    return result;
}
