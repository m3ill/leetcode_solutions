/*
 * Problem: LeetCode 1 - Two Sum
 * Pattern: Hash Map
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indexByValue;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int needed = target - nums[i];
            const auto it = indexByValue.find(needed);

            if (it != indexByValue.end()) {
                return {it->second, i};
            }

            indexByValue[nums[i]] = i;
        }

        return {};
    }
};
