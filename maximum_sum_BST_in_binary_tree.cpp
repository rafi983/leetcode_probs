#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

struct SubtreeInfo {
    bool isBST;
    int minVal;
    int maxVal;
    int sum;
};

class Solution {
    int maxSum = 0;

    SubtreeInfo postOrder(TreeNode* node) {
        if (!node) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        SubtreeInfo left = postOrder(node->left);
        SubtreeInfo right = postOrder(node->right);

        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            int currentSum = node->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);

            int currentMin = min(node->val, left.minVal);
            int currentMax = max(node->val, right.maxVal);

            return {true, currentMin, currentMax, currentSum};
        }

        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        postOrder(root);
        return maxSum;
    }
};
