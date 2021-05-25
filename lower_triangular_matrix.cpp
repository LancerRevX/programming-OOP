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
    this->print_method = (PrintMethod)data_queue.front(); data_queue.pop();
}

std::string LowerTriangularMatrix::format(PrintMethod print_method, bool filter) {
    if (filter) {
        return std::string();
    }
    std::string result = "Lower triangular matrix\n";
    if (print_method == PrintMethod::DEFAULT) {
        print_method = this->print_method;
    }
    switch (print_method) {
        case PrintMethod::BY_ROWS:
            result += "Print method: by rows\n";
            for (auto& row : this->data) {
                for (auto item : row) {
                    result += std::to_string(item) + " ";
                }
                result += ";\n";
            }
            break;
        case PrintMethod::BY_COLUMNS:
            result += "Print method: by columns\n";
            for (size_t j = 0; j < this->data.size(); j++) {
                for (size_t i = 0; i < this->data.size(); i++) {
                    result += std::to_string(this->data[i][j]) + " ";
                }
                result += ";\n";
            }
            break;
        case PrintMethod::ONE_DIMENSIONAL_ARRAY:
            result += "Print method: one dimensional array\n";
            for (auto& row : this->data) {
                for (auto item : row) {
                    result += std::to_string(item) + " ";
                }
            }
            result += ";\n";
            break;
    }
    return result;
}

std::string LowerTriangularMatrix::format_with(Matrix* matrix) {
    return matrix->format_with_lower_triangular_matrix();
}

std::string LowerTriangularMatrix::format_with_square_matrix() {
    return "Lower triangular matrix and square matrix\n";
}

std::string LowerTriangularMatrix::format_with_diagonal_matrix() {
    return "Lower triangular matrix and diagonal matrix\n";
}

std::string LowerTriangularMatrix::format_with_lower_triangular_matrix() {
    return "Two lower triangular matrices\n";
}