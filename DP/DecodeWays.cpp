#include "DecodeWays.hpp"

namespace DP {
    int numDecodings(const std::string& s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int n = s.length();
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i) {
            int one_digit = std::stoi(s.substr(i - 1, 1));
            int two_digits = std::stoi(s.substr(i - 2, 2));

            if (one_digit >= 1 && one_digit <= 9) {
                dp[i] += dp[i - 1];
            }
            if (two_digits >= 10 && two_digits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
}
