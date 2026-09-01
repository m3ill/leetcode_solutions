#include <algorithm>
#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int left = 0;
        int longest = 0;
        int zero_count = 0;

        for (int right = 0; right < static_cast<int>(nums.size()); ++right) {
            if (nums[right] == 0) {
                ++zero_count;
            }

            while (zero_count > k) {
                if (nums[left] == 0) {
                    --zero_count;
                }
                ++left;
            }

            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};
