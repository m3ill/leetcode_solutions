/*
* Problem: LeetCode 167 - Two Sum II - Input Array Is Sorted
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Two Pointers
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

#include <vector>

using std::vector;

class Solution {
public:
 vector<int> twoSum(vector<int>& numbers, int target) {
  int left = 0;
  int right = numbers.size()-1;

  while(left < right){
   int total = numbers[left] + numbers[right];

   if(total > target){
    right--;
   }else if(total < target){
    left++;
   }else{
    return {left+1,right+1};
   }
  }
  return {left+1,right+1};
 }
};