#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int count = 0;
        dfs(root, distance, count);
        return count;
    }

private:
    vector<int> dfs(TreeNode* node, int distance, int& count) {
        if (!node) return {};

        if (!node->left && !node->right) {
            return {1};
        }

        vector<int> leftDistances = dfs(node->left, distance, count);
        vector<int> rightDistances = dfs(node->right, distance, count);

        for (int l : leftDistances) {
            for (int r : rightDistances) {
                if (l + r <= distance) {
                    count++;
                }
            }
        }

        vector<int> result;
        for (int l : leftDistances) {
            if (l + 1 < distance) {
                result.push_back(l + 1);
            }
        }
        for (int r : rightDistances) {
            if (r + 1 < distance) {
                result.push_back(r + 1);
            }
        }

        return result;
    }
};
