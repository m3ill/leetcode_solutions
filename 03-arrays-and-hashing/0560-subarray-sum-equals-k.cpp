/*
 * GitHub: https://github.com/m3ill
 * Pattern: Prefix Sum / Hash Map
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCounter;
        prefixCounter[0] = 1;

        int count = 0;
        int prefixSum = 0;

        for (int num : nums) {
            prefixSum += num;
            count += prefixCounter[prefixSum - k];
            ++prefixCounter[prefixSum];
        }

        return count;
    }
};
