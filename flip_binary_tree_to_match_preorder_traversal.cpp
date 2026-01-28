#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    vector<int> flipped;
    int i;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        flipped.clear();
        i = 0;
        if (dfs(root, voyage)) {
            return flipped;
        }
        return {-1};
    }

    bool dfs(TreeNode* node, vector<int>& voyage) {
        if (!node) return true;

        if (node->val != voyage[i++]) return false;

        if (node->left && node->left->val != voyage[i]) {
            flipped.push_back(node->val);
            return dfs(node->right, voyage) && dfs(node->left, voyage);
        } else {
            return dfs(node->left, voyage) && dfs(node->right, voyage);
        }
    }
};
