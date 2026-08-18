/*
* Problem: LeetCode 238 - Product of Array Except Self
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Prefix / Suffix Product (Prefix Sum Variant)
 * Time Complexity: O(n)
 * Space Complexity: O(1) extra space (excluding the output array)
 */

#include <vector>

class solution {
    public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int n = nums.size();

        std::vector<int> prod(n, 1);

        int left = 1;
        for (int i = 0; i < n; ++i) {
            prod[i] *= left;
            left *= nums[i];

        }

        int right = 1;
        for (int i = n-1; i >= 0; ++i) {
            prod[i] *= right;
            right *= nums[i];
        }

        return prod;
    }


};
