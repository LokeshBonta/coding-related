# Unique Paths

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** A robot is located at the top-left corner of an `m x n` grid. The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. How many possible unique paths are there?
*   **Approach:** Dynamic programming. `dp[i][j]` stores the number of unique paths to reach cell `(i, j)`.
*   **Solution:** [UniquePaths.hpp](UniquePaths.hpp), [UniquePaths.cpp](UniquePaths.cpp), [UniquePaths_test.cpp](UniquePaths_test.cpp)
