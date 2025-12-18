#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root) return false;
        return checkPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool checkPath(ListNode* head, TreeNode* node) {
        if (!head) return true;
        if (!node) return false;
        if (head->val != node->val) return false;
        return checkPath(head->next, node->left) || checkPath(head->next, node->right);
    }
};
