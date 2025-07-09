//
// Created by cpastenc on 03/07/2025.
//

#include "KnapsackSolver.h"
#include <iostream>

using namespace std;

// Item class implementation
Item::Item() : id(0), value(0), weight(0) {}

Item::Item(int id, int value, int weight) : id(id), value(value), weight(weight) {

}

int Item::getId() const { return id; }
int Item::getValue() const { return value; }
int Item::getWeight() const { return weight; }

// KnapsackSolver class implementation
KnapsackSolver::KnapsackSolver(int cap) : capacity(cap), n(0) {
    // Initialize DP table
    for (int i = 0; i <= MAX_ITEMS; ++i) {
        for (int w = 0; w <= MAX_CAPACITY; ++w) {
            dp[i][w] = 0;
            taken[i][w] = false;
        }
    }
}

void KnapsackSolver::addItem(int id, int value, int weight) {
    if (n < MAX_ITEMS) {
        items[n] = Item(id, value, weight);
        ++n;
    }
}

void KnapsackSolver::solve() {
    // Fill DP table
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            // Don't take item i-1
            dp[i][w] = dp[i-1][w];
            taken[i][w] = false;

            // Take item i-1 if possible
            if (items[i-1].getWeight() <= w) {
                int valueWithItem = dp[i-1][w - items[i-1].getWeight()] + items[i-1].getValue();
                if (valueWithItem > dp[i][w]) {
                    dp[i][w] = valueWithItem;
                    taken[i][w] = true;
                }
            }
        }
    }
}

void KnapsackSolver::displaySolution() const {
    cout << "Maximum capacity: " << capacity << " units" << endl;
    cout << "Item Format: Item X (Value, Weight)" << endl;
    cout << "Selected items: ";

    // Reconstruct solution
    int w = capacity;
    int totalWeight = 0;
    int totalValue = 0;
    bool first = true;

    for (int i = n; i > 0 && w > 0; --i) {
        if (taken[i][w]) {
            if (!first) cout << " + ";
            cout << "Item " << items[i-1].getId()
                 << " (" << items[i-1].getValue() << "," << items[i-1].getWeight() << ")";
            totalWeight += items[i-1].getWeight();
            totalValue += items[i-1].getValue();
            w -= items[i-1].getWeight();
            first = false;
        }
    }

    cout << endl;
    cout << "Total value: " << totalValue << endl;
    cout << "Total weight: " << totalWeight << "/" << capacity
         << " (" << (100.0 * totalWeight / capacity) << "%)" << endl;
}

int KnapsackSolver::getMaxValue() const {
    return dp[n][capacity];
}

int KnapsackSolver::getTotalWeight() const {
    int w = capacity;
    int totalWeight = 0;

    for (int i = n; i > 0 && w > 0; --i) {
        if (taken[i][w]) {
            totalWeight += items[i-1].getWeight();
            w -= items[i-1].getWeight();
        }
    }

    return totalWeight;
}