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
    int countPaths(int n, const vector<vector<int>>& roads) {
        const int MOD = 1'000'000'007;
        vector<vector<pair<int, int>>> graph(n);
        graph.reserve(n);
        for (const auto& r : roads) {
            int u = r[0];
            int v = r[1];
            int w = r[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<long long> dist(n, numeric_limits<long long>::max());
        vector<int> ways(n, 0);
        using State = pair<long long, int>; // dist, node
        priority_queue<State, vector<State>, greater<State>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u]) {
                continue;
            }
            for (const auto& [v, w] : graph[u]) {
                long long nd = d + w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    ways[v] = ways[u];
                    pq.push({nd, v});
                } else if (nd == dist[v]) {
                    ways[v] += ways[u];
                    if (ways[v] >= MOD) {
                        ways[v] -= MOD;
                    }
                }
            }
        }

        return ways[n - 1];
    }
};
