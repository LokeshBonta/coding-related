#include "PartitionEqualSubsetSum.hpp"

namespace DP {
    bool canPartition(const std::vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        std::vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int s = targetSum; s >= num; --s) {
                dp[s] = dp[s] || dp[s - num];
            }
        }

        return dp[targetSum];
    }
}
