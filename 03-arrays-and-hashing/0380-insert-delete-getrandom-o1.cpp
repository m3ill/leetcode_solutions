/*
 * Problem: LeetCode 380 - Insert Delete GetRandom O(1)
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Array + Hash Map
 * Time Complexity: O(1) average for insert, remove, and getRandom
 * Space Complexity: O(n)
 */

#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> indexMap;

public:
    RandomizedSet() = default;

    bool insert(int val) {
        if (indexMap.contains(val)) {
            return false;
        }

        nums.push_back(val);
        indexMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!indexMap.contains(val)) {
            return false;
        }

        int index = indexMap[val];
        int lastValue = nums.back();

        nums[index] = lastValue;
        indexMap[lastValue] = index;

        nums.pop_back();
        indexMap.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
