#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;


class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<TreeNode*> path;
        int i = 0;
        int n = traversal.length();

        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            int val = 0;
            while (i < n && isdigit(traversal[i])) {
                val = val * 10 + (traversal[i] - '0');
                i++;
            }

            TreeNode* node = new TreeNode(val);

            if (depth == 0) {
                path.push_back(node);
            } else {
                while (path.size() > depth) {
                    path.pop_back();
                }
                TreeNode* parent = path.back();
                if (!parent->left) {
                    parent->left = node;
                } else {
                    parent->right = node;
                }
                path.push_back(node);
            }
        }

        return path.empty() ? nullptr : path[0];
    }
};
