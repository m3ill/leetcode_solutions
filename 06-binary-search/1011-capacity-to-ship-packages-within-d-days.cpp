/*
* Problem: LeetCode 1011 - Capacity To Ship Packages Within D Days
 * Author: Mertcan
 * GitHub: https://github.com/mSill
 * Pattern: Binary Search on Answer
 * Time Complexity: O(n * log(sum - max))
 * Space Complexity: O(1)
 */
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool canShip(std::vector<int>& weights,int days,int capacity){
        int current_days = 1;
        int current_load = 0;

        for(auto w : weights){
            if(current_load + w > capacity){
                current_days++;
                current_load = 0;
            }
            current_load += w;
        }

        return current_days <= days;
    }


    int shipWithinDays(std::vector<int>& weights, int days) {

        int max_weight = std::accumulate(weights.begin(),weights.end(),0);
        int min_weight = *std::max_element(weights.begin(), weights.end());

        while(min_weight <= max_weight){
            int mid = min_weight + (max_weight - min_weight) /2;
            if(canShip(weights,days,mid)){
                max_weight = mid-1;
            }else{
                min_weight = mid+1;
            }
        }

        return min_weight;


    }
};