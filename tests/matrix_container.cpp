#include <gtest/gtest.h>

#include "container.hpp"

using namespace std;

TEST(Container, read_and_format) {
    vector data {
        1,
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1
    };
    MatrixContainer container;
    container.read(data);
    ASSERT_EQ(
        container.format(), 
        "Square matrix\n"
        "Print method: by rows\n"
        "1 2 3 ;\n"
        "4 5 6 ;\n"
        "7 8 9 ;\n"
    );
}

TEST(Container, sort) {
    vector data {
        1,
        1, 
        3,
        1
    };
    vector data {
        1,
        1, 
        4,
        1
    };
    vector data {
        1,
        1, 
        9,
        1
    };
    MatrixContainer container
}

