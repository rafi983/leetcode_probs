#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
    vector<long long> allSums;

    long long treeSum(TreeNode* root) {
        if (!root) return 0;
        long long left = treeSum(root->left);
        long long right = treeSum(root->right);
        long long currentSum = root->val + left + right;
        allSums.push_back(currentSum);
        return currentSum;
    }

public:
    int maxProduct(TreeNode* root) {
        allSums.clear();
        long long totalSum = treeSum(root);
        long long best = 0;

        for (long long s : allSums) {
            best = max(best, s * (totalSum - s));
        }

        return best % 1000000007;
    }
};
