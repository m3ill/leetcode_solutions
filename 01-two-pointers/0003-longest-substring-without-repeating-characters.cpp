/*
 * Problem: LeetCode 3 - Longest Substring Without Repeating Characters
 * Pattern: Sliding Window
 * Time Complexity: O(n)
 * Space Complexity: O(min(n, alphabet))
 */

#include <algorithm>
#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> lastSeen;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            const auto it = lastSeen.find(s[right]);

            if (it != lastSeen.end() && it->second >= left) {
                left = it->second + 1;
            }

            lastSeen[s[right]] = right;
            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};
