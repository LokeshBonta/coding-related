#include "LCS.hpp"
#include <iostream>
#include <cassert>
#include <string>

void run_test(const std::string& text1, const std::string& text2, int expected, const std::string& test_name) {
    int result = DP::longestCommonSubsequence(text1, text2);
    std::cout << "Test: " << test_name << ", text1: \"" << text1 << "\", text2: \"" << text2 << "\", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Longest Common Subsequence tests...\n";

    run_test("abcde", "ace", 3, "Example 1");
    run_test("abc", "abc", 3, "Example 2");
    run_test("abc", "def", 0, "Example 3");
    run_test("bl", "yby", 1, "Single common char");
    run_test("", "", 0, "Empty strings");
    run_test("a", "", 0, "One empty string");
    run_test("", "b", 0, "Other empty string");
    run_test("ezupkr", "ubmrapg", 2, "Another example");

    std::cout << "All Longest Common Subsequence tests passed!\n";
    return 0;
}
