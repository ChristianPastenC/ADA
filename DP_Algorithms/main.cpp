#include <iostream>
#include "KnapsackSolver.h"
#include "RodCutter.h"
#include "MatrixChain.h"

using namespace std;

int main() {
    cout << "======== KNAPSACK PROBLEM ========" << endl;

    KnapsackSolver knapsack(140);

    int values[] = {79, 32, 47, 48, 26, 85, 33, 40, 45, 59};
    int weights[] = {85, 26, 48, 21, 22, 95, 43, 45, 55, 52};
    int itemsNum = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < itemsNum; ++i) {
        knapsack.addItem(i + 1, values[i], weights[i]);
    }

    knapsack.solve();
    knapsack.displaySolution();

    cout << endl;

    cout << "======== ROD CUTTING PROBLEM ========" << endl;

    int priceListTest[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int rodLengthTest = 4;
    int nTest = sizeof(priceListTest) / sizeof(priceListTest[0]);
    RodCutter rodCutter(priceListTest, nTest);
    rodCutter.solve(rodLengthTest);
    cout << "-------- TESTED EXAMPLE --------" << endl;
    rodCutter.displaySolution(rodLengthTest);

    int priceList[] = {1, 4, 10, 12, 15, 20, 21, 32, 31, 41, 51};
    int rodLength = 11;
    int n = sizeof(priceList) / sizeof(priceList[0]);

    RodCutter cutter(priceList, n);
    cutter.solve(rodLength);
    cout << "-------- REAL EXERCISE --------" << endl;
    cutter.displaySolution(rodLength);

    cout << endl;

    cout << "======== MATRIX CHAIN MULTIPLICATION ========" << endl;

    cout << "-------- TESTED EXAMPLE --------" << endl;
    int dimensionsTest[] = {30, 35, 15, 5, 10, 20, 25};
    int sizeTest = sizeof(dimensionsTest) / sizeof(dimensionsTest[0]);

    MatrixChain chainTest(dimensionsTest, sizeTest);
    chainTest.displayResult();

    cout << "-------- REAL EXERCISE --------" << endl;
    int dimensions[] = {5, 10, 3, 12, 5, 50, 6};
    int size = sizeof(dimensions) / sizeof(dimensions[0]);

    MatrixChain chain(dimensions, size);
    chain.displayResult();

    return 0;
}