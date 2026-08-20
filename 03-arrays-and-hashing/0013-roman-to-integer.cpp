/*
* Problem: LeetCode 13 - Roman to Integer
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Hash Table / String Parsing
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <string>
#include <unordered_map>

class Solution {
public:

    int romanToInt(std::string s) {
            std::unordered_map<char, int> RomanMap= {
                {'I',1},
                {'V' ,5},
                {'X',10},
                {'L',50},
                {'C',100},
                {'D',500},
                {'M',1000}
            };

            int total = 0;
            int n = s.length();

            for (int i = 0; i < n; i++) {
                if (i< n-1 && RomanMap[s[i]] < RomanMap[s[i+1]]) {
                    total -= RomanMap[s[i]];
                }else {
                    total += RomanMap[s[i]];
                }

            }

            return total;
    }

};
