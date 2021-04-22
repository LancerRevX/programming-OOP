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
    this->print_method = (PrintMethod)data_queue.front(); data_queue.pop();
}

std::string DiagonalMatrix::get_name() {
    return "Diagonal matrix";
    
}
