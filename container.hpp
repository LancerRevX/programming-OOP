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
    MatrixContainer() {}

    MatrixContainer(std::vector<int>& data) {
        this->read(data);
    }

    void read(std::vector<int>& data) {
        std::queue<int> data_queue {std::deque<int>(data.begin(), data.end())};
        while (data_queue.size()) {
            this->list.push_back(Matrix::create(data_queue));
        }
    }
    
    void sort() {
        this->list.sort([](Matrix* left, Matrix* right) {
            return left->get_sum() < right->get_sum();
        });
    }

    std::string format(Matrix::PrintMethod print_method = Matrix::PrintMethod::DEFAULT, bool filter = false) {
        if (list.size() == 0) {
            return "The container is empty!\n";
        }
        std::string result {"The container contains:\n"};
        for (auto item : this->list) {
            result += item->format(print_method, filter);
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
