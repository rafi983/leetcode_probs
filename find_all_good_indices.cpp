#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dec(n, 1);
        vector<int> inc(n, 1);

        // Compute length of non-increasing subarray ending at each index
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i-1]) {
                dec[i] = dec[i-1] + 1;
            }
        }

        // Compute length of non-decreasing subarray starting at each index
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] <= nums[i+1]) {
                inc[i] = inc[i+1] + 1;
            }
        }

        vector<int> result;
        // Check condition for each index i
        for (int i = k; i < n - k; ++i) {
            if (dec[i-1] >= k && inc[i+1] >= k) {
                result.push_back(i);
            }
        }

        return result;
    }
};

