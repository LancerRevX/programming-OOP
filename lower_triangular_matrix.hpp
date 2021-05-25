#pragma once



#include "matrix.hpp"

class LowerTriangularMatrix : public Matrix {
public: 
    LowerTriangularMatrix();
    LowerTriangularMatrix(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) override;
    virtual std::string format(PrintMethod print_method = DEFAULT, bool filter = false) override;
    virtual std::string format_with(Matrix* matrix);
    virtual std::string format_with_square_matrix() override;
    virtual std::string format_with_diagonal_matrix() override;
    virtual std::string format_with_lower_triangular_matrix() override;
};