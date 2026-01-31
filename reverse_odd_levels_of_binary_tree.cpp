#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root->left, root->right, 1);
        return root;
    }

private:
    void dfs(TreeNode* node1, TreeNode* node2, int level) {
        if (!node1 || !node2) return;

        if (level % 2 != 0) {
            swap(node1->val, node2->val);
        }

        dfs(node1->left, node2->right, level + 1);
        dfs(node1->right, node2->left, level + 1);
    }
};
