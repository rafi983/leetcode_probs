#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
    int sum = 0;
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root) {
            bstToGst(root->right);
            sum += root->val;
            root->val = sum;
            bstToGst(root->left);
        }
        return root;
    }
};

void printTree(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);

    cout << "[";
    bool first = true;
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (!first) cout << ", ";
        first = false;

        if (curr) {
            cout << curr->val;
            q.push(curr->left);
            q.push(curr->right);
        } else {
            cout << "null";
        }
    }
    cout << "]" << endl;
}
