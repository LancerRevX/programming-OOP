#pragma once



#include "matrix.hpp"

class LowerTriangularMatrix : public Matrix {
public: 
    LowerTriangularMatrix();
    LowerTriangularMatrix(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) override;
    virtual std::string format(PrintMethod print_method = DEFAULT) override;
};