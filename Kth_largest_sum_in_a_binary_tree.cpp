#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <functional>

using namespace std;


class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1;

        vector<long long> levelSums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            long long currentLevelSum = 0;
            for(int i=0; i<size; ++i){
                TreeNode* node = q.front();
                q.pop();
                currentLevelSum += node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            levelSums.push_back(currentLevelSum);
        }

        if (levelSums.size() < k) return -1;

        sort(levelSums.begin(), levelSums.end(), greater<long long>());

        return levelSums[k-1];
    }
};
