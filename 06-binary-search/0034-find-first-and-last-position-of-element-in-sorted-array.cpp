#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        std::vector<int> result(2, -1);
        int left = 0;
        int right = static_cast<int>(nums.size()) - 1;

        // Find the leftmost occurrence.
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                result[0] = mid;
                right = mid - 1;
            }
        }

        left = 0;
        right = static_cast<int>(nums.size()) - 1;

        // Find the rightmost occurrence.
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target < nums[mid]) {
                right = mid - 1;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                result[1] = mid;
                left = mid + 1;
            }
        }

        return result;
    }
};
