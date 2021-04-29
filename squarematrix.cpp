#include "squarematrix.hpp"

#include <string>

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
    this->print_method = (PrintMethod)data_queue.front(); data_queue.pop();
}

std::string SquareMatrix::format(PrintMethod print_method, bool filter) {
    std::string result {"Square matrix\n"};
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

