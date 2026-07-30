#include <vector>
//
// Created by Mertc on 30.07.2026.
//
class Solution {
    public:

    void backTracking(std::vector<int>& nums,std::vector<int> &current,std::vector<bool>& visited,std::vector<std::vector<int>> &result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0;i < nums.size(); ++i) {
            if (visited[i]) continue;


            visited[i] = true;
            current.push_back(nums[i]);

            backTracking(nums, current, visited, result);

            visited[i] = false;
            current.pop_back();
        }

    }





    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited (nums.size(), false);

        backTracking(nums, current, visited, result);


        return result;

    }
};