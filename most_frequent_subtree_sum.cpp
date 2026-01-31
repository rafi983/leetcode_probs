#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
private:
    unordered_map<int, int> sumFrequency;
    int maxFreq = 0;

    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);
        int subtreeSum = node->val + leftSum + rightSum;

        sumFrequency[subtreeSum]++;
        maxFreq = max(maxFreq, sumFrequency[subtreeSum]);

        return subtreeSum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        sumFrequency.clear();
        maxFreq = 0;

        dfs(root);

        vector<int> result;
        for (auto const& [sum, count] : sumFrequency) {
            if (count == maxFreq) {
                result.push_back(sum);
            }
        }
        return result;
    }
};
