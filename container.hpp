#include <list>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>

#include "squarematrix.hpp"

template <typename T>
class Container {
public:
    Container() {

    }

    void read(std::vector<int>& data) {
        std::queue<int> data_queue {std::deque<int>(data.begin(), data.end())};
        while (data_queue.size()) {
            this->list.push_back(T::create(data_queue));
        }
    }

    std::string format(bool filter = false) {
        if (list.size() == 0) {
            return "Container is empty!\n";
        }
        std::string result;
        for (auto item : this->list) {
            if (not filter or dynamic_cast<SquareMatrix*>(item)) {
                result += item->format();
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

    ~Container() {
        this->clear();
    }
private:
    std::list<T*> list;
};
