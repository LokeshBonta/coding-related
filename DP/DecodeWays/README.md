# Decode Ways

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** A message containing letters from `A-Z` is being encoded to numbers using the following mapping: 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26. Given a non-empty string containing only digits, determine the total number of ways to decode it.
*   **Approach:** Dynamic programming. `dp[i]` stores the number of ways to decode `s[0...i-1]`.
*   **Solution:** [DecodeWays.hpp](DecodeWays.hpp), [DecodeWays.cpp](DecodeWays.cpp), [DecodeWays_test.cpp](DecodeWays_test.cpp)
