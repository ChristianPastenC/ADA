//
// Created by cpastenc on 06/07/2025.
//

#ifndef RODCUTTER_H
#define RODCUTTER_H



#define MAX_LENGTH 100

class RodCutter {
private:
    int prices[MAX_LENGTH]; // prices[i] = price of rod length i + 1
    int dp[MAX_LENGTH];     // dp[i] = max price for rod length i
    int cuts[MAX_LENGTH];   // cuts[i] = first cut to get dp[i]
    int size;

public:
    RodCutter(int inputPrices[], int n);

    void solve(int rodLength);
    void displaySolution(int rodLength);

    int getMaxPrice(int rodLength) const;
};



#endif //RODCUTTER_H
