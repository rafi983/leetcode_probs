#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;


class Solution {
private:
    vector<int> sortedVals;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        sortedVals.push_back(node->val);
        inorder(node->right);
    }

    TreeNode* buildTree(int start, int end) {
        if (start > end) return nullptr;

        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(sortedVals[mid]);

        root->left = buildTree(start, mid - 1);
        root->right = buildTree(mid + 1, end);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        sortedVals.clear();
        inorder(root);
        return buildTree(0, sortedVals.size() - 1);
    }
};
