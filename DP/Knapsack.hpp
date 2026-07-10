#ifndef KNAPSACK_HPP
#define KNAPSACK_HPP

#include <vector>
#include <algorithm>

namespace DP {
    int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values);
}

#endif // KNAPSACK_HPP
