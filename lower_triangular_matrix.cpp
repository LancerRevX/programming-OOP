#include "lower_triangular_matrix.hpp"

#include <string>

LowerTriangularMatrix::LowerTriangularMatrix() {

}

LowerTriangularMatrix::LowerTriangularMatrix(std::queue<int>& data_queue) {
    this->read(data_queue);
}

void LowerTriangularMatrix::read(std::queue<int>& data_queue) {
    auto size {data_queue.front()}; data_queue.pop();
    this->data.resize(size);
    for (size_t i {0}; i < size; i++) {
        data[i].resize(size);
        for (size_t j {0}; j < size; j += 1) {
            if (j <= i) {
                data[i][j] = data_queue.front(); data_queue.pop();
            } else {
                data[i][j] = 0;
            }
        }
    }
}

std::string LowerTriangularMatrix::format() {
    std::string result = "Lower triangular matrix:\n";
    for (auto& row : this->data) {
        for (auto item : row) {
            result += std::to_string(item) + " ";
        }
        result += ";\n";
    }
    return result;
}