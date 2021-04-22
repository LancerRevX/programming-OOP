#pragma once

#include <cstdlib>
#include <iostream>
#include <vector>

#include "matrix.hpp"

class DiagonalMatrix : public Matrix {
public:
    DiagonalMatrix();
    DiagonalMatrix(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) override;
    virtual std::string format(PrintMethod print_method = DEFAULT, bool filter = false) override;
};