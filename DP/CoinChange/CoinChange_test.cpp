#include "CoinChange.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void run_test(const std::vector<int>& coins, int amount, int expected, const std::string& test_name) {
    int result = DP::coinChange(coins, amount);
    std::cout << "Test: " << test_name << ", Coins: {";
    for (int coin : coins) {
        std::cout << coin << ", ";
    }
    std::cout << "}, Amount: " << amount << ", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Coin Change tests...\n";

    run_test({1, 2, 5}, 11, 3, "Example 1");
    run_test({2}, 3, -1, "Example 2");
    run_test({1}, 0, 0, "Example 3");
    run_test({1}, 1, 1, "Single coin, single amount");
    run_test({1}, 2, 2, "Single coin, multiple amount");
    run_test({186, 419, 83, 408}, 6249, 20, "Large values");
    run_test({3, 5}, 7, -1, "No solution");

    std::cout << "All Coin Change tests passed!\n";
    return 0;
}
