# Knapsack Problem (0/1 Knapsack)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. Each item can either be put completely into the knapsack or not.
*   **Approach:** Dynamic programming. `dp[i][w]` stores the maximum value that can be obtained with items `0...i-1` and capacity `w`.
*   **Solution:** [Knapsack.hpp](Knapsack.hpp), [Knapsack.cpp](Knapsack.cpp), [Knapsack_test.cpp](Knapsack_test.cpp)
