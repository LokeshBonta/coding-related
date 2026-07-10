#include "WordBreak.hpp"

namespace DP {
    bool wordBreak(const std::string& s, const std::unordered_set<std::string>& wordDict) {
        int n = s.length();
        std::vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
