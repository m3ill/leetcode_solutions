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
class solution {
    public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> result(n,0);
        std::stack<int> stack;

        for (int i = 0; i < n; i++) {
            while (!stack.empty() && temperatures[stack.top()] < temperatures[i]) {
                int top = stack.top();
                stack.pop();
                int answer_index = i - top;
                result[top] = temperatures[answer_index];
            }
            stack.push(i);
        }

        return result;


    }
};