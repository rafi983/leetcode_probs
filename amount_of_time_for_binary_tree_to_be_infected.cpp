#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adj;
        buildGraph(root, nullptr, adj);

        queue<int> q;
        q.push(start);

        unordered_set<int> visited;
        visited.insert(start);

        int minutes = -1;

        while (!q.empty()) {
            int size = q.size();
            minutes++;
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                for (int neighbor : adj[curr]) {
                    if (visited.find(neighbor) == visited.end()) {
                        visited.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
        }

        return minutes == -1 ? 0 : minutes;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<int, vector<int>>& adj) {
        if (!node) return;

        if (parent) {
            adj[node->val].push_back(parent->val);
            adj[parent->val].push_back(node->val);
        }

        buildGraph(node->left, node, adj);
        buildGraph(node->right, node, adj);
    }
};
