/*
* Problem: LeetCode 134 - Gas Station
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Greedy
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>

class solution {
    public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total_gas = 0;
        int current_gas = 0;
        int start_index = 0;
        int n = gas.size();


        for (int i = 0; i < n; ++i) {
            int net_gas = gas[i]-cost[i];

            total_gas += net_gas;
            current_gas += net_gas;

            if (current_gas < 0) {
                start_index = i+1;
                current_gas = 0;
            }
        }

        if (total_gas < 0) {
            return -1;
        }

        return start_index;


    }
};