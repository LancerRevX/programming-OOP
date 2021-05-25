#pragma once

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

#include "matrix.hpp"

class SquareMatrix : public Matrix {
public:
    SquareMatrix();
    SquareMatrix(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) override;
    virtual std::string format() override;
    virtual std::string format_with(Matrix* right) override;
    virtual std::string format_with_square_matrix() override;
    virtual std::string format_with_diagonal_matrix() override;
};
