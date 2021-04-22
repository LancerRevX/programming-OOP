#include <list>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>

#include "matrix.hpp"

class MatrixContainer {
public:
    MatrixContainer() {

    }

    void read(std::vector<int>& data) {
        std::queue<int> data_queue {std::deque<int>(data.begin(), data.end())};
        while (data_queue.size()) {
            this->list.push_back(Matrix::create(data_queue));
        }
    }

    std::string format(Matrix::PrintMethod print_method = Matrix::PrintMethod::DEFAULT) {
        if (list.size() == 0) {
            return "Container is empty!\n";
        }
        std::string result;
        for (auto item : this->list) {
            result += item->format(print_method);
        }
        return result;
    }

    void clear() {
        for (auto item : this->list) {
            delete item;
        }
        this->list.clear();
    }

    ~MatrixContainer() {
        this->clear();
    }
private:
    std::list<Matrix*> list;
};
