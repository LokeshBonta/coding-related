#include "HouseRobber.hpp"
#include <iostream>
#include <cassert>
#include <vector>

void run_test(const std::vector<int>& nums, int expected, const std::string& test_name) {
    int result = DP::rob(nums);
    std::cout << "Test: " << test_name << ", Nums: {";
    for (int num : nums) {
        std::cout << num << ", ";
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
    std::cout << "Running House Robber tests...\n";

    run_test({1, 2, 3, 1}, 4, "Example 1");
    run_test({2, 7, 9, 3, 1}, 12, "Example 2");
    run_test({0}, 0, "Single house, zero money");
    run_test({1}, 1, "Single house, some money");
    run_test({1, 2}, 2, "Two houses");
    run_test({2, 1, 1, 2}, 4, "Another example");

    std::cout << "All House Robber tests passed!\n";
    return 0;
}
