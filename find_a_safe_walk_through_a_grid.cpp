#include <vector>
#include <deque>
#include <iostream>
#include <limits.h>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        dist[0][0] = grid[0][0];
        if (grid[0][0] == 0) {
            dq.push_front({0, 0});
        } else {
            dq.push_back({0, 0});
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        while (!dq.empty()) {
            pair<int, int> curr = dq.front();
            dq.pop_front();
            int x = curr.first;
            int y = curr.second;

            if (x == m - 1 && y == n - 1) {

                return dist[x][y] <= health - 1;
            }

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = dist[x][y] + grid[nx][ny];
                    if (newDist < dist[nx][ny]) {
                        dist[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        return false;
    }
};
