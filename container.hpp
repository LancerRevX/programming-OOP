#include <list>
#include <memory>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>
#include <queue>

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

    std::string format() {
        if (list.size() == 0) {
            return "Container is empty!\n";
        }
        std::string result;
        for (auto item : this->list) {
            result += item->format();
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

    ~Container() {
        this->clear();
    }
private:
    std::list<T*> list;
};
