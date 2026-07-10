# Edit Distance (Levenshtein Distance)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given two strings `word1` and `word2`, find the minimum number of operations required to convert `word1` to `word2`. Operations allowed are insert, delete, or replace a character.
*   **Approach:** Dynamic programming. `dp[i][j]` stores the minimum operations to convert `word1[0...i-1]` to `word2[0...j-1]`.
*   **Solution:** [EditDistance.hpp](EditDistance.hpp), [EditDistance.cpp](EditDistance.cpp), [EditDistance_test.cpp](EditDistance_test.cpp)
