# Coin Change

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
*   **Approach:** Dynamic programming. `dp[i]` stores the minimum number of coins to make amount `i`.
*   **Solution:** [CoinChange.hpp](CoinChange.hpp), [CoinChange.cpp](CoinChange.cpp), [CoinChange_test.cpp](CoinChange_test.cpp)
