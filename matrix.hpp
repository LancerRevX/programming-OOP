#pragma once

#include <iostream>
#include <queue>
#include <vector>

class Matrix
{
public:
    static Matrix* create(std::queue<int>& data_queue);
    virtual void read(std::queue<int>& data_queue) = 0;
    virtual std::string format() = 0;
private:
    enum Type {
        SQUARE = 1,
        DIAGONAL = 2,
        LOWER_TRIANGULAR = 3
    };
protected:
    std::vector<std::vector<int>> data;
};
