#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string tree2str(TreeNode* root) {
        if (!root) {
            return "";
        }

        string s = to_string(root->val);

        if (root->left || root->right) {
            s += "(" + tree2str(root->left) + ")";
        }

        if (root->right) {
            s += "(" + tree2str(root->right) + ")";
        }

        return s;
    }
};
