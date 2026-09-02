/*
 * Problem: LeetCode 735 - Asteroid Collision
 * Author: Mertcan
 * GitHub: https://github.com/m3ill
 * Pattern: Monotonic Stack
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include <cstdlib>
#include <stack>
#include <vector>

class Solution {
public:
    std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
        std::stack<int> colliding;

        for (int asteroid : asteroids) {
            bool alive = true;

            while (alive && asteroid < 0 && !colliding.empty() && colliding.top() > 0) {
                if (colliding.top() < -asteroid) {
                    colliding.pop();
                } else if (colliding.top() == -asteroid) {
                    colliding.pop();
                    alive = false;
                } else {
                    alive = false;
                }
            }

            if (alive) {
                colliding.push(asteroid);
            }
        }

        std::vector<int> result(colliding.size());
        for (int index = static_cast<int>(result.size()) - 1; index >= 0; --index) {
            result[index] = colliding.top();
            colliding.pop();
        }

        return result;
    }
};
