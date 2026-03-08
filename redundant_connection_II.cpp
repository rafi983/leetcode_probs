#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = static_cast<int>(edges.size());
        vector<int> directParent(n + 1, 0);
        vector<int> firstEdge;
        vector<int> secondEdge;
        int secondEdgeIndex = -1;

        for (int i = 0; i < n; ++i) {
            int parentNode = edges[i][0];
            int childNode = edges[i][1];

            if (directParent[childNode] == 0) {
                directParent[childNode] = parentNode;
            } else {
                firstEdge = {directParent[childNode], childNode};
                secondEdge = edges[i];
                secondEdgeIndex = i;
            }
        }

        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        for (int node = 1; node <= n; ++node) {
            parent[node] = node;
        }

        vector<int> cycleEdge;
        for (int i = 0; i < n; ++i) {
            if (i == secondEdgeIndex) {
                continue;
            }

            if (!unite(edges[i][0], edges[i][1])) {
                cycleEdge = edges[i];
            }
        }

        if (secondEdgeIndex == -1) {
            return cycleEdge;
        }

        if (cycleEdge.empty()) {
            return secondEdge;
        }

        return firstEdge;
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
            int temp = rootA;
            rootA = rootB;
            rootB = temp;
        }

        parent[rootB] = rootA;
        if (rank[rootA] == rank[rootB]) {
            rank[rootA]++;
        }

        return true;
    }
};
