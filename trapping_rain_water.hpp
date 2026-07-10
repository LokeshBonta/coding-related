#ifndef TRAPPING_RAIN_WATER_HPP
#define TRAPPING_RAIN_WATER_HPP

#include <vector>

/**
 * @brief Trapping Rain Water problem solution
 * 
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it can trap after raining.
 * 
 * Algorithm: Two-pointer approach
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @param height Vector of non-negative integers representing elevation heights
 * @return The total amount of trapped water
 */
namespace trapping_rain_water {
    int trap(const std::vector<int>& height);
} // namespace trapping_rain_water

#endif // TRAPPING_RAIN_WATER_HPP