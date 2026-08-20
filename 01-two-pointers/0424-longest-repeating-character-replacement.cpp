//
// Created by Mertcan on 13.08.2026.
//


#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        std::vector<int> letters(26, 0);
        int left = 0;
        int max_frequency = 0;
        int result = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            max_frequency = std::max(max_frequency, ++letters[s[right] - 'A']);

            while (right - left + 1 - max_frequency > k) {
                --letters[s[left] - 'A'];
                ++left;
            }

            result = std::max(result, right - left + 1);
        }

        return result;
    }
};
