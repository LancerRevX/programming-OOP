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
        "The container contains:\n"
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
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1,

        2,
        3,
        1, 2, 3,
        1,

        3,
        3,
        1,
        2, 3,
        4, 5, 6,
        1
    };
    MatrixContainer container(data);
    container.sort();
    EXPECT_EQ(
        container.format(),
        "The container contains:\n"
        "Diagonal matrix\n"
        "Print method: by rows\n"
        "1 0 0 ;\n"
        "0 2 0 ;\n"
        "0 0 3 ;\n"
        "Lower triangular matrix\n"
        "Print method: by rows\n"
        "1 0 0 ;\n"
        "2 3 0 ;\n"
        "4 5 6 ;\n"
        "Square matrix\n"
        "Print method: by rows\n"
        "1 2 3 ;\n"
        "4 5 6 ;\n"
        "7 8 9 ;\n"
    );
}

TEST(Container, clear) {
    vector data {
        1,
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1,

        2,
        3,
        1, 2, 3,
        1,

        3,
        3,
        1,
        2, 3,
        4, 5, 6,
        1
    };
    MatrixContainer container(data);
    container.clear();
    EXPECT_EQ(
        container.format(),
        "The container is empty!\n"
    );
}

