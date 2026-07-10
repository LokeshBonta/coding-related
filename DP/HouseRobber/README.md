# House Robber

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night. Given an integer array `nums` representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*   **Approach:** Dynamic programming. `dp[i]` stores the maximum amount that can be robbed up to house `i`.
*   **Solution:** [HouseRobber.hpp](HouseRobber.hpp), [HouseRobber.cpp](HouseRobber.cpp), [HouseRobber_test.cpp](HouseRobber_test.cpp)
