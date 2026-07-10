#include "CoinChange.hpp"
#include <limits>

namespace DP {
    int coinChange(const std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, std::numeric_limits<int>::max());
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != std::numeric_limits<int>::max()) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == std::numeric_limits<int>::max() ? -1 : dp[amount];
    }
}
