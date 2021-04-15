build:
	g++ main.cpp matrix.cpp squarematrix.cpp diagonalmatrix.cpp -oapp.exe

build-debug:
	g++ -g main.cpp matrix.cpp squarematrix.cpp diagonalmatrix.cpp -oapp.exe