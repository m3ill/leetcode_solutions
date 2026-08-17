//
// Created by Mertc on 6.08.2026.
//

#include <algorithm>
#include <vector>

class solution {
    public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long total_hours= 0;
            for (auto p :piles) {
                total_hours += (p+mid-1)/mid;
            }

            if (total_hours > h) {
                low = mid + 1;
            }else {
                high = mid - 1;
                ans = mid;
            }
        }

        return ans;
    }
};