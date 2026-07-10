#include "DecodeWays.hpp"
#include <iostream>
#include <cassert>
#include <string>

void run_test(const std::string& s, int expected, const std::string& test_name) {
    int result = DP::numDecodings(s);
    std::cout << "Test: " << test_name << ", String: \"" << s << "\", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Decode Ways tests...\n";

    run_test("12", 2, "Example 1");
    run_test("226", 3, "Example 2");
    run_test("0", 0, "Example 3");
    run_test("1", 1, "Single digit");
    run_test("10", 1, "Zero at end");
    run_test("2101", 1, "Zero in middle");
    run_test("12345", 3, "Long string");
    run_test("27", 1, "Invalid two-digit");
    run_test("11106", 2, "Another example");

    std::cout << "All Decode Ways tests passed!\n";
    return 0;
}
