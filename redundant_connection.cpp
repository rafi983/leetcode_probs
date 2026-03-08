#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = static_cast<int>(edges.size());
        parent.resize(n + 1);
        rank.assign(n + 1, 0);

        for (int node = 1; node <= n; ++node) {
            parent[node] = node;
        }

        vector<int> redundant;
        for (const auto& edge : edges) {
            if (!unite(edge[0], edge[1])) {
                redundant = edge;
            }
        }

        return redundant;
    }

private:
    vector<int> parent;
    vector<int> rank;

    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }

    bool unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) {
            return false;
        }

        if (rank[rootA] < rank[rootB]) {
            swap(rootA, rootB);
        }

        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) {
            rank[rootA]++;
        }

        return true;
    }
};
