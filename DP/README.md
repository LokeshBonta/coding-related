# Dynamic Programming (DP) Questions

This section contains a collection of classic Dynamic Programming problems frequently asked in interviews by top tech companies like Google, Microsoft, Apple, and Amazon. Each problem includes a brief description and the general DP approach.

---

## 1. Longest Increasing Subsequence (LIS)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given an unsorted array of integers, find the length of the longest increasing subsequence.
*   **Approach:** Dynamic programming. `dp[i]` stores the length of the longest increasing subsequence ending at index `i`.
*   **Solution:** [LIS.hpp](LIS.hpp), [LIS.cpp](LIS.cpp), [LIS_test.cpp](LIS_test.cpp)

## 2. Edit Distance (Levenshtein Distance)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given two strings `word1` and `word2`, find the minimum number of operations required to convert `word1` to `word2`. Operations allowed are insert, delete, or replace a character.
*   **Approach:** Dynamic programming. `dp[i][j]` stores the minimum operations to convert `word1[0...i-1]` to `word2[0...j-1]`.
*   **Solution:** [EditDistance.hpp](EditDistance.hpp), [EditDistance.cpp](EditDistance.cpp), [EditDistance_test.cpp](EditDistance_test.cpp)

## 3. Coin Change

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money. Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
*   **Approach:** Dynamic programming. `dp[i]` stores the minimum number of coins to make amount `i`.
*   **Solution:** [CoinChange.hpp](CoinChange.hpp), [CoinChange.cpp](CoinChange.cpp), [CoinChange_test.cpp](CoinChange_test.cpp)

## 4. Word Break

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.
*   **Approach:** Dynamic programming. `dp[i]` is `true` if `s[0...i-1]` can be segmented.
*   **Solution:** [WordBreak.hpp](WordBreak.hpp), [WordBreak.cpp](WordBreak.cpp), [WordBreak_test.cpp](WordBreak_test.cpp)

## 5. Unique Paths

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** A robot is located at the top-left corner of an `m x n` grid. The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid. How many possible unique paths are there?
*   **Approach:** Dynamic programming. `dp[i][j]` stores the number of unique paths to reach cell `(i, j)`.
*   **Solution:** [UniquePaths.hpp](UniquePaths.hpp), [UniquePaths.cpp](UniquePaths.cpp), [UniquePaths_test.cpp](UniquePaths_test.cpp)

## 6. Longest Common Subsequence (LCS)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given two strings `text1` and `text2`, return the length of their longest common subsequence.
*   **Approach:** Dynamic programming. `dp[i][j]` stores the length of the LCS of `text1[0...i-1]` and `text2[0...j-1]`.
*   **Solution:** [LCS.hpp](LCS.hpp), [LCS.cpp](LCS.cpp), [LCS_test.cpp](LCS_test.cpp)

## 7. Knapsack Problem (0/1 Knapsack)

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given weights and values of `n` items, put these items in a knapsack of capacity `W` to get the maximum total value in the knapsack. Each item can either be put completely into the knapsack or not.
*   **Approach:** Dynamic programming. `dp[i][w]` stores the maximum value that can be obtained with items `0...i-1` and capacity `w`.
*   **Solution:** [Knapsack.hpp](Knapsack.hpp), [Knapsack.cpp](Knapsack.cpp), [Knapsack_test.cpp](Knapsack_test.cpp)

## 8. House Robber

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*   **Approach:** Dynamic programming. `dp[i]` stores the maximum amount that can be robbed up to house `i`.
*   **Solution:** [HouseRobber.hpp](HouseRobber.hpp), [HouseRobber.cpp](HouseRobber.cpp), [HouseRobber_test.cpp](HouseRobber_test.cpp)

## 9. Decode Ways

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** A message containing letters from `A-Z` is being encoded to numbers using the following mapping: 'A' -> 1, 'B' -> 2, ..., 'Z' -> 26. Given a non-empty string containing only digits, determine the total number of ways to decode it.
*   **Approach:** Dynamic programming. `dp[i]` stores the number of ways to decode `s[0...i-1]`.
*   **Solution:** [DecodeWays.hpp](DecodeWays.hpp), [DecodeWays.cpp](DecodeWays.cpp), [DecodeWays_test.cpp](DecodeWays_test.cpp)

## 10. Partition Equal Subset Sum

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given a non-empty array `nums` containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
*   **Approach:** Dynamic programming. This is a variation of the subset sum problem. `dp[i]` is `true` if a sum `i` can be formed.
*   **Solution:** [PartitionEqualSubsetSum.hpp](PartitionEqualSubsetSum.hpp), [PartitionEqualSubsetSum.cpp](PartitionEqualSubsetSum.cpp), [PartitionEqualSubsetSum_test.cpp](PartitionEqualSubsetSum_test.cpp)

