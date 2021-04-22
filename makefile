build:
	g++ main.cpp matrix.cpp squarematrix.cpp diagonalmatrix.cpp lower_triangular_matrix.cpp -oapp.exe

build-debug:
	g++ -g main.cpp matrix.cpp squarematrix.cpp diagonalmatrix.cpp lower_triangular_matrix.cpp -oapp.exe