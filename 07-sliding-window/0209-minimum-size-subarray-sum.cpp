#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int left = 0;
        int right = 0;
        int sum = 0;

        while (right < nums.size()) {
            sum += nums[right];

            while (sum >= target) {
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        if (len == INT_MAX) {
            len = 0;
        }

        return len;
    }
};
