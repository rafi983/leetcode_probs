#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // Check if it's a leaf node
        if (!root->left && !root->right) {
            return targetSum == root->val;
        }

        // Recursively check left and right subtrees
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
