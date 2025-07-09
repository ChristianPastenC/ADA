//
// Created by cpastenc on 08/07/2025.
//

#include "MatrixChain.h"
#include <iostream>

using namespace std;

MatrixChain::MatrixChain(int* dimensions, int size) {
    p = dimensions;
    N = size - 1;

    m = new int*[N];
    s = new int*[N];
    for (int i = 0; i < N; ++i) {
        m[i] = new int[N];
        s[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            m[i][j] = (i == j) ? 0 : INT_MAX;
            s[i][j] = 0;
        }
    }

    computeOptimalOrder();
}

MatrixChain::~MatrixChain() {
    for (int i = 0; i < N; ++i) {
        delete[] m[i];
        delete[] s[i];
    }
    delete[] m;
    delete[] s;
}

void MatrixChain::computeOptimalOrder() {
    for (int chainLen = 2; chainLen <= N; ++chainLen) {
        for (int i = 0; i <= N - chainLen; ++i) {
            int j = i + chainLen - 1;
            for (int k = i; k < j; ++k) {
                int cost = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }
}

void MatrixChain::printOptimalParenthesis(int i, int j) const {
    if (i == j) {
        cout << "A" << (i + 1);
    } else {
        cout << "(";
        printOptimalParenthesis(i, s[i][j]);
        cout << " * ";
        printOptimalParenthesis(s[i][j] + 1, j);
        cout << ")";
    }
}

void MatrixChain::displayResult() const {
    cout << "Minimum number of scalar multiplications: " << m[0][N - 1] << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParenthesis(0, N - 1);
    cout << endl;
}

int MatrixChain::getMinMultiplications() const {
    return m[0][N - 1];
}