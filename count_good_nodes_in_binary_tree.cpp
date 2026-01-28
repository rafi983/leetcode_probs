#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }

private:
    int countGoodNodes(TreeNode* node, int maxVal) {
        if (!node) return 0;

        int count = 0;
        if (node->val >= maxVal) {
            count = 1;
            maxVal = node->val;
        }

        count += countGoodNodes(node->left, maxVal);
        count += countGoodNodes(node->right, maxVal);

        return count;
    }
};
