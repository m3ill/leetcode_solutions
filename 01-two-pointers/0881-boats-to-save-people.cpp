/*
* Problem: LeetCode 881 - Boats to Save People
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Two Pointers
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(),people.end());

        int left = 0;
        int right = people.size()-1;
        int counter = 0;
        while(left <= right){
            if(people[right]+people[left] <= limit){
                left++;
                right--;
            }else{
                right--;
            }
            counter++;
        }
        return counter;
    }
};
