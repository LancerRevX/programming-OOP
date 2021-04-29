#include <gtest/gtest.h>

#include "diagonalmatrix.hpp"

using namespace std;

TEST(DiagonalMatrix, read_and_format) {
    queue data_queue {deque({
        3, 
        1, 2, 3,
        1
    })};
    DiagonalMatrix matrix(data_queue);
    ASSERT_EQ(
        matrix.format(), 
        "Diagonal matrix\n"
        "Print method: by rows\n"
        "1 0 0 ;\n"
        "0 2 0 ;\n"
        "0 0 3 ;\n"
    );
}