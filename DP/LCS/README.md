# Longest Common Subsequence (LCS)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given two strings `text1` and `text2`, return the length of their longest common subsequence.
*   **Approach:** Dynamic programming. `dp[i][j]` stores the length of the LCS of `text1[0...i-1]` and `text2[0...j-1]`.
*   **Solution:** [LCS.hpp](LCS.hpp), [LCS.cpp](LCS.cpp), [LCS_test.cpp](LCS_test.cpp)
