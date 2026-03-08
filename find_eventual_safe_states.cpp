#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = static_cast<int>(graph.size());
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);

        for (int node = 0; node < n; ++node) {
            outDegree[node] = static_cast<int>(graph[node].size());
            for (int neighbor : graph[node]) {
                reverseGraph[neighbor].push_back(node);
            }
        }

        queue<int> q;
        for (int node = 0; node < n; ++node) {
            if (outDegree[node] == 0) {
                q.push(node);
            }
        }

        vector<bool> safe(n, false);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (int prev : reverseGraph[node]) {
                outDegree[prev]--;
                if (outDegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        vector<int> result;
        for (int node = 0; node < n; ++node) {
            if (safe[node]) {
                result.push_back(node);
            }
        }

        return result;
    }
};
