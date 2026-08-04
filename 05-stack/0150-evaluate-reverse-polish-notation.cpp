/*
* Problem: LeetCode 150 - Evaluate Reverse Polish Notation
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<long long> st;

        for (const auto& s : tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                long long b = st.top(); st.pop();
                long long a = st.top(); st.pop();

                if (s == "+") st.push(a + b);
                else if (s == "-") st.push(a - b);
                else if (s == "*") st.push(a * b);
                else if (s == "/") st.push(a / b);
            }
            else {
                st.push(std::stoll(s));
            }
        }

        return st.top();
    }
};