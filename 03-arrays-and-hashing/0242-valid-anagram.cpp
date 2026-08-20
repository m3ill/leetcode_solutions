/*
 * GitHub: https://github.com/m3ill
 * Pattern: Hash Map / Frequency Array
 * Time Complexity: O(n) (n: string uzunluğu)
 * Space Complexity: O(k) (k: benzersiz karakter sayısı, en fazla O(1) [26 karakter])
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool is_zero(std::unordered_map<char,int> &freq){
        for(const auto &[key,value] : freq){
            if(value != 0){
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {
        size_t s_size = s.size();
        size_t t_size = t.size();
        if(s_size != t_size) return false;

        std::unordered_map<char, int> freq;

        for(char &c : s){
            freq[c]++;
        }

        for(char &c: t){
            freq[c]--;
        }

        return is_zero(freq) ? true : false;

    }
};
