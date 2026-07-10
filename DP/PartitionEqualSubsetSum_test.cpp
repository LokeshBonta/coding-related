#include "PartitionEqualSubsetSum.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <numeric>

void run_test(const std::vector<int>& nums, bool expected, const std::string& test_name) {
    bool result = DP::canPartition(nums);
    std::cout << "Test: " << test_name << ", Nums: {";
    for (int num : nums) {
        std::cout << num << ", ";
    }
    std::cout << "}, Expected: " << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false");
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Partition Equal Subset Sum tests...\n";

    run_test({1, 5, 11, 5}, true, "Example 1");
    run_test({1, 2, 3, 5}, false, "Example 2");
    run_test({1, 2, 3, 4, 5, 6, 7}, true, "Sum is even");
    run_test({1, 1}, true, "Two equal numbers");
    run_test({100}, false, "Single number");
    run_test({2, 2, 3, 5}, false, "No partition");
    run_test({1, 2, 5}, false, "Odd total sum");

    std::cout << "All Partition Equal Subset Sum tests passed!\n";
    return 0;
}
