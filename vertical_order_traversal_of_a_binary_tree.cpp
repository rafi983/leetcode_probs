#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int, int, int>> nodes;

        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end());

        vector<vector<int>> ans;
        if (nodes.empty()) return ans;

        int currCol = get<0>(nodes[0]);
        vector<int> colVals;

        for (const auto& t : nodes) {
            int col = get<0>(t);
            int val = get<2>(t);

            if (col != currCol) {
                ans.push_back(colVals);
                colVals.clear();
                currCol = col;
            }
            colVals.push_back(val);
        }
        ans.push_back(colVals); // push the last column

        return ans;
    }

private:
    void dfs(TreeNode* node, int row, int col, vector<tuple<int, int, int>>& nodes) {
        if (!node) return;

        nodes.emplace_back(col, row, node->val);
        dfs(node->left, row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};
