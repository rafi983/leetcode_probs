#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int findTheCity(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = numeric_limits<int>::max() / 4;
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (const auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (dist[i][k] == INF) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    if (dist[k][j] == INF) {
                        continue;
                    }
                    int nd = dist[i][k] + dist[k][j];
                    if (nd < dist[i][j]) {
                        dist[i][j] = nd;
                    }
                }
            }
        }

        int bestCity = -1;
        int bestCount = numeric_limits<int>::max();
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                if (dist[i][j] <= distanceThreshold) {
                    ++count;
                }
            }
            if (count < bestCount || (count == bestCount && i > bestCity)) {
                bestCount = count;
                bestCity = i;
            }
        }

        return bestCity;
    }
};