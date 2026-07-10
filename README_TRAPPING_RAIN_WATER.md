# Trapping Rain Water Problem

This solution implements the classic "Trapping Rain Water" algorithm using a two-pointer approach for optimal efficiency.

## Problem Description

Given `n` non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

### Example
Input: `[0,1,0,2,1,0,1,3,2,1,2,1]`  
Output: `6`  

Visualization:
```
       █
       █  █
█      ████  █
█  █   ████  █
█████  ████████
0 1  0 2  1  0 1 3 2 1 2 1
```

## Solution Approach

**Two-Pointer Technique**: 
- Use two pointers starting from both ends of the array
- Maintain maximum height seen so far from both sides
- Move the pointer with smaller height inward
- Calculate trapped water based on the difference between max height and current height

## Time & Space Complexity

- **Time Complexity**: O(n) - single pass through the array
- **Space Complexity**: O(1) - only using a constant amount of extra space

## Implementation Details

The algorithm works by observing that:
1. Water trapped at any position depends on the minimum of the maximum heights to its left and right
2. We can efficiently calculate this using two pointers moving towards each other
3. At each step, we know that the water level at the shorter side is determined by the current max on that side

## API Reference

```cpp
#include "trapping_rain_water.hpp"

int result = trapping_rain_water::trap(const std::vector<int>& height);
```

### Parameters
- `height`: Vector of non-negative integers representing elevation heights

### Return Value
- The total amount of trapped rainwater

## Usage Example

```cpp
#include "trapping_rain_water.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> elevations = {0,1,0,2,1,0,1,3,2,1,2,1};
    int trapped = trapping_rain_water::trap(elevations);
    std::cout << "Trapped water: " << trapped << std::endl;  // Output: 6
    return 0;
}
```

## Building and Testing

```bash
# Compile
g++ -std=c++17 -o test_trapping_rain_water test_trapping_rain_water.cpp trapping_rain_water.cpp

# Run tests
./test_trapping_rain_water
```

## Requirements

- C++17 or later
- Standard Template Library (STL)

## Related Problems

- [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
- [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)