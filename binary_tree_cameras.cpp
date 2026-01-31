#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
private:
    int cameras;

    int dfs(TreeNode* node) {
        if (!node) return 1;

        int left = dfs(node->left);
        int right = dfs(node->right);

        if (left == 0 || right == 0) {
            cameras++;
            return 2;
        }

        if (left == 2 || right == 2) {
            return 1;
        }

        return 0;
    }

public:
    int minCameraCover(TreeNode* root) {
        cameras = 0;
        if (dfs(root) == 0) {
            cameras++;
        }
        return cameras;
    }
};
