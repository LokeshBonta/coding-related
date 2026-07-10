#include "UniquePaths.hpp"
#include <iostream>
#include <cassert>

void run_test(int m, int n, int expected, const std::string& test_name) {
    int result = DP::uniquePaths(m, n);
    std::cout << "Test: " << test_name << ", m: " << m << ", n: " << n << ", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Unique Paths tests...\n";

    run_test(3, 7, 28, "Example 1");
    run_test(3, 2, 3, "Example 2");
    run_test(7, 3, 28, "Example 3");
    run_test(3, 3, 6, "3x3 grid");
    run_test(1, 1, 1, "1x1 grid");
    run_test(1, 5, 1, "1xN grid");
    run_test(5, 1, 1, "Nx1 grid");

    std::cout << "All Unique Paths tests passed!\n";
    return 0;
}
