#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, const vector<vector<int>>& flights, int src, int dst, int k) {
        const int INF = numeric_limits<int>::max() / 4;
        vector<int> dist(n, INF);
        dist[src] = 0;

        for (int i = 0; i <= k; ++i) {
            vector<int> next = dist;
            for (const auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if (dist[u] == INF) {
                    continue;
                }
                next[v] = min(next[v], dist[u] + w);
            }
            dist.swap(next);
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};
