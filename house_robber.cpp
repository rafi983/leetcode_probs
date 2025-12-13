#include <vector>
#include <algorithm>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int current = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};

