#include<iostream>
#include "Matrix.hpp"

int main(){
    int rows, cols;

    std::cin >> rows >> cols;
    Matrix A(rows, cols);
    std::cin >> A;

    // Matrix A(rows, cols, matrixA);       // matrixA为已知的矩阵名

    std::cin >> rows >> cols;
    Matrix B(rows, cols);
    std::cin >> B;

    // Matrix C(rows, cols);
    // C = A;                              // 将A赋值给C

    // std::cout << A * B;
    std::cout << A + B;
    std::cout << A - B;
    if(A == B)
        std::cout << "equal" << std::endl;
    else
        std::cout << "not equal" << std::endl;

    return 0;
}
