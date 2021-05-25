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

    std::string multimethod() {
        std::string result {"Container multimethod:\n"};
        for (size_t i {0}; i < this->list.size(); i++) {
            for (size_t j {i + 1}; j < this->list.size(); j++) {
                auto left_iterator {this->list.begin()};
                std::advance(left_iterator, i);
                auto* left {*left_iterator};
                
                auto right_iterator {this->list.begin()};
                std::advance(right_iterator, j);
                auto* right {*right_iterator};

                result += left->format_with(right);
                result += right->format();
                result += left->format();
            }
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
