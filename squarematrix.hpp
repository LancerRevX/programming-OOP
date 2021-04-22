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
    virtual std::string format(bool filter) override;
};
