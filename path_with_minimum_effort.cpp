#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumEffortPath(const vector<vector<int>>& heights) {
        int rows = static_cast<int>(heights.size());
        int cols = static_cast<int>(heights[0].size());
        vector<vector<int>> dist(rows, vector<int>(cols, numeric_limits<int>::max()));
        using State = tuple<int, int, int>; // effort, r, c
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0][0] = 0;
        pq.emplace(0, 0, 0);

        const int dr[4] = {1, -1, 0, 0};
        const int dc[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            auto [effort, r, c] = pq.top();
            pq.pop();
            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }
            if (effort != dist[r][c]) {
                continue;
            }
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue;
                }
                int edge = abs(heights[r][c] - heights[nr][nc]);
                int nextEffort = max(effort, edge);
                if (nextEffort < dist[nr][nc]) {
                    dist[nr][nc] = nextEffort;
                    pq.emplace(nextEffort, nr, nc);
                }
            }
        }
        return 0;
    }
};
