/*
* Problem: LeetCode 283 - Move Zeroes
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
    void moveZeroes(vector<int>& nums) {
        //bu yerleştirilecek yerleri tutacak
        int left = 0;
        //bu sayı mı 0 mı ona bakacak
        int right = 0;

        while(right < static_cast<int>(nums.size())){
            if(nums[right] != 0){
                std::swap(nums[right], nums[left]);

                left++;
            }
            right++;
        }
    }
};
