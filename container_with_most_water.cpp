#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = (int)height.size();
        if (n < 2) return 0;

        int l = 0, r = n - 1;
        int best = 0;

        while (l < r) {
            int h = min(height[l], height[r]);
            int area = (r - l) * h;

            if (area > best) {
                best = area;
            }

            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return best;
    }
};
