#include "WordBreak.hpp"
#include <iostream>
#include <cassert>
#include <string>
#include <unordered_set>

void run_test(const std::string& s, const std::unordered_set<std::string>& wordDict, bool expected, const std::string& test_name) {
    bool result = DP::wordBreak(s, wordDict);
    std::cout << "Test: " << test_name << ", String: \"" << s << "\", Expected: " << (expected ? "true" : "false") << ", Got: " << (result ? "true" : "false");
    if (result == expected) {
        std::cout << " -> Passed\n";
    } else {
        std::cout << " -> Failed\n";
        assert(false && "Test failed");
    }
}

int main() {
    std::cout << "Running Word Break tests...\n";

    run_test("leetcode", {"leet", "code"}, true, "Example 1");
    run_test("applepenapple", {"apple", "pen"}, true, "Example 2");
    run_test("catsandog", {"cats", "dog", "sand", "and", "cat"}, false, "Example 3");
    run_test("", {}, true, "Empty string, empty dict");
    run_test("a", {"a"}, true, "Single char, single word");
    run_test("aaaaaaa", {"aaaa", "aaa"}, true, "Repeated words");
    run_test("ab", {"a", "b"}, true, "Two words");
    run_test("ab", {"a", "c"}, false, "No match");

    std::cout << "All Word Break tests passed!\n";
    return 0;
}
