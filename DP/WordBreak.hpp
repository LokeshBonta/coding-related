#ifndef WORD_BREAK_HPP
#define WORD_BREAK_HPP

#include <string>
#include <vector>
#include <unordered_set>

namespace DP {
    bool wordBreak(const std::string& s, const std::unordered_set<std::string>& wordDict);
}

#endif // WORD_BREAK_HPP
