/*
* Problem: LeetCode 739 - Daily Temperatures
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Monotonic Stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */


#include <stack>
#include <vector>
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n,0);
        std::stack<int> indices;

        for (int i = 0; i < n; i++) {
            while (!indices.empty() && temperatures[indices.top()] < temperatures[i]) {
                int previous_day = indices.top();
                indices.pop();
                result[previous_day] = i - previous_day;
            }
            indices.push(i);
        }

        return result;


    }
};
