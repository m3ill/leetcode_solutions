/*
* Problem: LeetCode 217 - Contains Duplicate
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Hash Set
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seenNumbers;
        size_t n = nums.size();
        for (size_t i = 0; i < n; i++) {
            if (seenNumbers.contains(nums[i])) {
                return true;
            } else {
                seenNumbers.insert(nums[i]);
            }
        }

        return false;
    }
};