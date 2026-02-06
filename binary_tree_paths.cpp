#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) {
            dfs(root, to_string(root->val), result);
        }
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node->left && !node->right) {
            result.push_back(path);
            return;
        }

        if (node->left) {
            dfs(node->left, path + "->" + to_string(node->left->val), result);
        }

        if (node->right) {
            dfs(node->right, path + "->" + to_string(node->right->val), result);
        }
    }
};
