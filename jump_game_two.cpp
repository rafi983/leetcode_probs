#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(const vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return 0;

        int steps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                ++steps;
                currentEnd = farthest;
            }
        }

        return steps;
    }
};

#ifdef RUN_JUMP_GAME_TWO_MAIN
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    cout << sol.jump(nums) << "\n";
    return 0;
}
#endif
