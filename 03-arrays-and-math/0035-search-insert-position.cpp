//
// Created by Mertcan on 29.07.2026.
//

#include <vector>

class Solution {
    public:
    int searchInsert(std::vector<int>& v, int target) {

        int left = 0, right = (int)v.size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (v[mid] == target) {
                return mid;
            }
            else if (v[mid] < target) {
                left = mid + 1;
            }else if (v[mid] > target) {
                right = mid - 1;
            }
        }
        return left;

    }
};
