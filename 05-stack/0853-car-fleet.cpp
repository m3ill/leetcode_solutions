/*
 * Problem: LeetCode 853 - Car Fleet
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Sorting + fleet-time comparison
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        std::vector<std::pair<int, int>> cars;

        for (int i = 0; i < static_cast<int>(position.size()); i++) {
            cars.push_back({position[i], speed[i]});
        }

        std::sort(cars.begin(), cars.end());

        std::vector<double> cars_finish_time;
        cars_finish_time.reserve(cars.size());
        for (int i = 0; i < static_cast<int>(cars.size()); i++) {
            double time = static_cast<double>(target - cars[i].first) / cars[i].second;
            cars_finish_time.push_back(time);
        }

        double ref_time = cars_finish_time.back();
        int fleet = static_cast<int>(cars.size());

        for (int i = static_cast<int>(cars.size()) - 2; i >= 0; i--) {
            if (cars_finish_time[i] <= ref_time) {
                fleet--;
            } else {
                ref_time = cars_finish_time[i];
            }
        }

        return fleet;
    }
};
