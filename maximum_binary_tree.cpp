#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* build(const vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int max_idx = left;
        for (int i = left + 1; i <= right; ++i) {
            if (nums[i] > nums[max_idx]) {
                max_idx = i;
            }
        }

        TreeNode* node = new TreeNode(nums[max_idx]);
        node->left = build(nums, left, max_idx - 1);
        node->right = build(nums, max_idx + 1, right);

        return node;
    }
};
