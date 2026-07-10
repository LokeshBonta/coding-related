#include "Knapsack.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void run_test(int W, const std::vector<int>& weights, const std::vector<int>& values, int expected, const std::string& test_name) {
    int result = DP::knapsack(W, weights, values);
    std::cout << "Test: " << test_name << ", W: " << W << ", Weights: {";
    for (int w : weights) {
        std::cout << w << ", ";
    }
    std::cout << "}, Values: {";
    for (int v : values) {
        std::cout << v << ", ";
    }
    std::cout << "}, Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Knapsack tests...\n";

    run_test(10, {2, 3, 4, 5}, {3, 4, 5, 6}, 10, "Example 1");
    run_test(50, {10, 20, 30}, {60, 100, 120}, 220, "Example 2");
    run_test(0, {1, 2, 3}, {10, 20, 30}, 0, "Zero capacity");
    run_test(10, {}, {}, 0, "Empty items");
    run_test(1, {10}, {100}, 0, "Item too heavy");
    run_test(7, {3, 4, 5}, {4, 5, 6}, 9, "Another example");

    std::cout << "All Knapsack tests passed!\n";
    return 0;
}
