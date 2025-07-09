//
// Created by cpastenc on 08/07/2025.
//

#ifndef MATRIXCHAIN_H
#define MATRIXCHAIN_H



class MatrixChain {
private:
    int* p;   // Array of dimensions (of size N+1)
    int N;    // Number of matrix (N = size of p - 1)
    int** m;  // Minimum cost table
    int** s;  // Cut-off indexes

    void computeOptimalOrder();
    void printOptimalParenthesis(int i, int j) const;

public:
    MatrixChain(int* dimensions, int size);
    ~MatrixChain();

    void displayResult() const;
    int getMinMultiplications() const;
};




#endif //MATRIXCHAIN_H
