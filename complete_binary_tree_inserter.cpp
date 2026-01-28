#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

class CBTInserter {
    TreeNode* root;
    deque<TreeNode*> q;

public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push_back(root);

        while (true) {
            TreeNode* node = q.front();
            if (node->left && node->right) {
                q.pop_front();
                q.push_back(node->left);
                q.push_back(node->right);
            } else {
                if (node->left) {
                    q.push_back(node->left);
                }
                break;
            }
        }
    }

    int insert(int v) {
        TreeNode* node = q.front();
        TreeNode* newNode = new TreeNode(v);

        if (!node->left) {
            node->left = newNode;
        } else {
            node->right = newNode;
            q.pop_front();
        }

        q.push_back(newNode);

        return node->val;
    }

    TreeNode* get_root() {
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
        TreeNode* node = q.front();
        q.pop();
        if (!first) cout << ", ";
        cout << node->val;
        first = false;
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << "]" << endl;
}
