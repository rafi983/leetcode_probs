#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> maxProb(n, 0.0);
        maxProb[start] = 1.0;

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == end) {
                return prob;
            }

            if (prob < maxProb[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                double edgeProb = edge.second;

                if (maxProb[u] * edgeProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * edgeProb;
                    pq.push({maxProb[v], v});
                }
            }
        }

        return maxProb[end];
    }
};

