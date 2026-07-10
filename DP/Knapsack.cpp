#include "Knapsack.hpp"

namespace DP {
    int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values) {
        int n = weights.size();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int w = 1; w <= W; ++w) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }
        return dp[n][W];
    }
}
