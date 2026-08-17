/*
* Problem: LeetCode 49 - Group Anagrams
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Hash Map / Sorting
 * Time Complexity: O(n * k * log(k)) (n: kelime sayısı, k: en uzun kelimenin uzunluğu)
 * Space Complexity: O(n * k)
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<string>> results;
        std::unordered_map<std::string, std::vector<std::string>> groups;
        size_t n = strs.size();
        for(size_t i = 0; i < n;i++){
            std::string word = strs[i];
            std::string temp = word;
            std::sort(temp.begin(),temp.end());

            auto it = groups.find(temp);

            if(it != groups.end()){
                it->second.push_back(word);
            }else{
                std::vector<std::string> values;
                values.push_back(word);
                groups.insert({temp,values});
            }
        }

        for(const auto& [key, values]:groups ){
            results.push_back(values);
        }
        return results;


    }
};