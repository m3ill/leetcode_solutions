/*
* GitHub: https://github.com/m3ill
 * Pattern: Hash Map / Sorting
 * Time Complexity: O(n + m log m) (n: nums uzunluğu, m: benzersiz eleman sayısı)
 * Space Complexity: O(m) (m: benzersiz eleman sayısı)
 */

#include <algorithm>
#include <unordered_map>
#include <vector>


using namespace std;



class Solution {
public:
 vector<int> topKFrequent(vector<int>& nums, int k) {
  std::unordered_map<int ,int> freq;
  std::vector<std::pair<int,int>> freq_vec;
  for(int &k : nums){
   freq[k]++;
  }


  for(const auto& [key,value] : freq){
   freq_vec.push_back({key,value});
  }

  std::sort(freq_vec.begin(),freq_vec.end(),[](const auto& a,const auto& b){
      return a.second > b.second;
  });

  std::vector<int> result;
  for (int i = 0; i < k;i++){
   result.push_back(freq_vec[i].first);
  }
  return result;





 }
};