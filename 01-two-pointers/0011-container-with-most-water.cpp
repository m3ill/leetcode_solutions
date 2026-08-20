/*
* Problem: LeetCode 11 - Container With Most Water
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Two Pointers
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>


class Solution {
public:
    int maxArea(std::vector<int>& height) {
            int left = 0, right = height.size() - 1;
            int max_area = 0;
            while (left < right) {
                int width = right - left;

                int h = std::min(height[left], height[right]);
                max_area = std::max(max_area, width * h);
                if (height[left] < height[right]) {
                    left++;
                }else {
                    right--;
                }
            }
            return max_area;
    }
};
