#include "EditDistance.hpp"
#include <iostream>
#include <cassert>
#include <string>

void run_test(const std::string& word1, const std::string& word2, int expected, const std::string& test_name) {
    int result = DP::minDistance(word1, word2);
    std::cout << "Test: " << test_name << ", word1: \"" << word1 << "\", word2: \"" << word2 << "\", Expected: " << expected << ", Got: " << result;
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Edit Distance tests...\n";

    run_test("horse", "ros", 3, "Example 1");
    run_test("intention", "execution", 5, "Example 2");
    run_test("", "", 0, "Empty strings");
    run_test("a", "", 1, "One empty string");
    run_test("", "a", 1, "Other empty string");
    run_test("abc", "abc", 0, "Identical strings");
    run_test("kitten", "sitting", 3, "Standard example");
    run_test("flaw", "lawn", 2, "Another example");

    std::cout << "All Edit Distance tests passed!\n";
    return 0;
}
