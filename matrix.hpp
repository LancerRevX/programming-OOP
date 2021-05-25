#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Matrix {
public:
    enum PrintMethod {
        DEFAULT, BY_ROWS, BY_COLUMNS, ONE_DIMENSIONAL_ARRAY
    };

    static Matrix* create(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) = 0;
    int get_sum();
    virtual std::string format(PrintMethod print_method = DEFAULT, bool filter = false) = 0;
    virtual std::string format_with(Matrix* matrix) = 0;
    virtual std::string format_with_square_matrix() = 0;
    virtual std::string format_with_diagonal_matrix() = 0;
private:
    enum Type {
        SQUARE = 1,
        DIAGONAL = 2,
        LOWER_TRIANGULAR = 3
    };
protected:
    std::vector<std::vector<int>> data;
    PrintMethod print_method;
};
