//
// Created by cpastenc on 06/07/2025.
//

#include "RodCutter.h"
#include <iostream>

using namespace std;

RodCutter::RodCutter(int inputPrices[], int n) {
    size = n;
    for (int i = 0; i < n; ++i)
        prices[i] = inputPrices[i];
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
        cuts[i] = 0;
    }
}

void RodCutter::solve(int rodLength) {
    for (int len = 1; len <= rodLength; ++len) {
        int maxVal = -1;
        for (int cut = 1; cut <= len && cut <= size; ++cut) {
            int val = prices[cut - 1] + dp[len - cut];
            if (val > maxVal) {
                maxVal = val;
                cuts[len] = cut;
            }
        }
        dp[len] = maxVal;
    }
}

void RodCutter::displaySolution(int rodLength) {
    cout << "Maximum price for rod of length " << rodLength << " is: " << dp[rodLength] << endl;
    cout << "Optimal cuts: ";
    int n = rodLength;
    int totalPrice = 0;
    bool first = true;
    while (n > 0) {
        int cut = cuts[n];
        int cutPrice = prices[cut - 1];
        totalPrice += cutPrice;

        if (!first) cout << " + ";
        cout << cut << "(" << cutPrice << ")";
        n -= cut;
        first = false;
    }
    cout << " = " << totalPrice << endl;
}

int RodCutter::getMaxPrice(int rodLength) const {
    return dp[rodLength];
}
