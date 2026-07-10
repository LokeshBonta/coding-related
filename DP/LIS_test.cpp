#include "LIS.hpp"
#include <iostream>
#include <vector>
#include <cassert>

void run_test(const std::vector<int>& nums, int expected, const std::string& test_name) {
    int result = DP::lengthOfLIS(nums);
    std::cout << "Test: " << test_name << ", Input: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << ", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running LIS tests...\n";

    run_test({10, 9, 2, 5, 3, 7, 101, 18}, 4, "Example 1");
    run_test({0, 1, 0, 3, 2, 3}, 4, "Example 2");
    run_test({7, 7, 7, 7, 7, 7, 7}, 1, "All same elements");
    run_test({}, 0, "Empty array");
    run_test({1}, 1, "Single element");
    run_test({1, 3, 6, 7, 9, 4, 10, 5, 6}, 6, "Mixed elements");
    run_test({-1, 0, 1, 2, 3}, 5, "Negative and positive increasing");
    run_test({3, 2, 1, 0}, 1, "Decreasing sequence");

    std::cout << "All LIS tests passed!\n";
    return 0;
}
