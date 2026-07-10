#include "trapping_rain_water.hpp"
#include <iostream>
#include <vector>
#include <cassert>

void test_case(const std::vector<int>& height, int expected) {
    int result = trapping_rain_water::trap(height);
    std::cout << "Input: [";
    for (size_t i = 0; i < height.size(); ++i) {
        std::cout << height[i];
        if (i < height.size() - 1) std::cout << ",";
    }
    std::cout << "] => Output: " << result << " (Expected: " << expected << ")" << std::endl;
    assert(result == expected);
}

int main() {
    std::cout << "Testing Trapping Rain Water problem..." << std::endl;
    
    // Test case 1: Basic case
    test_case({0,1,0,2,1,0,1,3,2,1,2,1}, 6);
    
    // Test case 2: All zeros
    test_case({0,0,0,0}, 0);
    
    // Test case 3: Single element
    test_case({5}, 0);
    
    // Test case 4: Increasing sequence
    test_case({1,2,3,4,5}, 0);
    
    // Test case 5: Decreasing sequence
    test_case({5,4,3,2,1}, 0);
    
    // Test case 6: Plateau
    test_case({3,3,3,3,3}, 0);
    
    // Test case 7: Mixed pattern
    test_case({2,0,2}, 2);
    
    // Test case 8: Larger example
    test_case({4,2,0,3,2,5}, 9);
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}