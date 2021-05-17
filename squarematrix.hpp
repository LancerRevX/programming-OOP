#pragma once

#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>

#include "matrix.hpp"

class SquareMatrix : public Matrix {
public:
    SquareMatrix(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) override;
    virtual std::string format(PrintMethod print_method = PrintMethod::DEFAULT, bool filter = false) override;
};
