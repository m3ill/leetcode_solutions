/*
* Problem: LeetCode 128 - Longest Consecutive Sequence
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Arrays & Hashing
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;

class Solution {
public:
 int longestConsecutive(vector<int>& nums) {
  std::unordered_set<int> numSet;
  if(nums.size() == 0) return 0;

  for(int i : nums){
   numSet.insert(i);
  }


  int result = 1;
  for(int num : numSet){
   if(!numSet.contains(num-1)){
    int current_length = 1;
    int j = 1;
    while(numSet.contains(num+j)){
     current_length++;
     j++;
    }
    result = std::max(current_length,result);
   }
  }
  return result;

 }
};