# Word Break

*   **Companies:** Google, Microsoft, Amazon, Apple
*   **Problem:** Given a string `s` and a dictionary of strings `wordDict`, return `true` if `s` can be segmented into a space-separated sequence of one or more dictionary words.
*   **Approach:** Dynamic programming. `dp[i]` is `true` if `s[0...i-1]` can be segmented.
*   **Solution:** [WordBreak.hpp](WordBreak.hpp), [WordBreak.cpp](WordBreak.cpp), [WordBreak_test.cpp](WordBreak_test.cpp)
