#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        // If both are null, they are equivalent
        if (!root1 && !root2) return true;
        // If one is null or values are different, they are not equivalent
        if (!root1 || !root2 || root1->val != root2->val) return false;

        // Check if they are equivalent without flip OR with flip
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
