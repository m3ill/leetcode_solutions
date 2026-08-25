/*
 * Problem: LeetCode 125 - Valid Palindrome
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Two Pointers
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0;
        int right = static_cast<int>(s.size()) - 1;

        while (left <= right) {
            if (!std::isalnum(static_cast<unsigned char>(s[left]))) {
                ++left;
                continue;
            }

            if (!std::isalnum(static_cast<unsigned char>(s[right]))) {
                --right;
                continue;
            }

            if (std::tolower(static_cast<unsigned char>(s[left])) !=
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};
