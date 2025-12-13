#include <queue>
#include <unordered_set>
#include <string>

class Solution {
public:
    int racecar(int target) {
        std::queue<std::pair<int, int>> q;
        std::unordered_set<std::string> visited;

        q.push({0, 1});
        visited.insert("0,1");
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [pos, speed] = q.front();
                q.pop();

                if (pos == target) {
                    return steps;
                }

                int newPos = pos + speed;
                int newSpeed = speed * 2;
                std::string stateA = std::to_string(newPos) + "," + std::to_string(newSpeed);
                if (newPos > 0 && newPos < 2 * target && visited.find(stateA) == visited.end()) {
                    visited.insert(stateA);
                    q.push({newPos, newSpeed});
                }

                int revSpeed = (speed > 0) ? -1 : 1;
                std::string stateR = std::to_string(pos) + "," + std::to_string(revSpeed);
                if (visited.find(stateR) == visited.end()) {
                    visited.insert(stateR);
                    q.push({pos, revSpeed});
                }
            }
            steps++;
        }

        return -1;
    }
};

