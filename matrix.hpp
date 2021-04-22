#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Matrix
{
public:
    enum PrintMethod {
        BY_ROWS, BY_COLUMNS, ONE_DIMENSIONAL_ARRAY
    };

    static Matrix* create(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) = 0;
    std::string format(PrintMethod print_method);
    virtual std::string get_name() = 0;
private:
    enum Type {
        SQUARE = 1,
        DIAGONAL = 2
    };
protected:
    std::vector<std::vector<int>> data;
};
