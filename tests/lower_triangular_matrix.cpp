#include <gtest/gtest.h>

#include "lower_triangular_matrix.hpp"

using namespace std;

TEST(LowerTriangularMatrix, read_and_format) {
    queue data_queue {deque({
        3, 
        1, 2, 3, 4, 5, 6,
        1
    })};
    LowerTriangularMatrix matrix(data_queue);
    ASSERT_EQ(
        matrix.format(), 
        "Lower triangular matrix\n"
        "Print method: by rows\n"
        "1 0 0 ;\n"
        "2 3 0 ;\n"
        "4 5 6 ;\n"
    );
}