#include "matrix.hpp"
#include "squarematrix.hpp"
#include "diagonalmatrix.hpp"

#include <string>

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

std::string Matrix::format(PrintMethod print_method) {
    std::string result {this->get_name() + ":\n"};
    switch (print_method) {
        case PrintMethod::BY_ROWS:  
            for (auto& row : this->data) {
                for (auto item : row) {
                    result += std::to_string(item) + " ";
                }
                result += ";\n";
            }
            break;
        case PrintMethod::BY_COLUMNS:
            for (size_t j = 0; j < this->data.size(); j++) {
                for (size_t i = 0; i < this->data.size(); i++) {
                    result += std::to_string(this->data[i][j]) + " ";
                }
                result += ";\n";
            }
            break;
        case PrintMethod::ONE_DIMENSIONAL_ARRAY:
            for (auto& row : this->data) {
                for (auto item : row) {
                    result += std::to_string(item) + " ";
                }
            }
            break;
    }
    return result;
}