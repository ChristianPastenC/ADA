//
// Created by cpastenc on 03/07/2025.
//

#ifndef KNAPSACKSOLVER_H
#define KNAPSACKSOLVER_H

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

class Item {
private:
    int id;
    int value;
    int weight;

public:
    Item();
    Item(int id, int value, int weight);

    int getId() const;
    int getValue() const;
    int getWeight() const;
};

class KnapsackSolver {
private:
    Item items[MAX_ITEMS];
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];
    bool taken[MAX_ITEMS + 1][MAX_CAPACITY + 1];
    int n;
    int capacity;

public:
    KnapsackSolver(int cap);

    void addItem(int id, int value, int weight);
    void solve();
    void displaySolution() const;

    int getMaxValue() const;
    int getTotalWeight() const;
};

#endif // KNAPSACKSOLVER_H