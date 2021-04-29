#include <gtest/gtest.h>

#include "squarematrix.hpp"

using namespace std;

TEST(SquareMatrix, read_and_format) {
    queue data_queue {deque({
        3, 
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,
        1
    })};
    SquareMatrix matrix(data_queue);
    ASSERT_EQ(
        matrix.format(), 
        "Square matrix\n"
        "Print method: by rows\n"
        "1 2 3 ;\n"
        "4 5 6 ;\n"
        "7 8 9 ;\n"
    );
}
