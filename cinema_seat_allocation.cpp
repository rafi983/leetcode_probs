#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            reserved[row] |= (1 << col);
        }

        int max_families = (n - reserved.size()) * 2;

        for (auto& [row, mask] : reserved) {
            bool left = true;
            // Check 2, 3, 4, 5
            if ((mask & (1 << 2)) || (mask & (1 << 3)) || (mask & (1 << 4)) || (mask & (1 << 5))) {
                left = false;
            }

            bool right = true;
            // Check 6, 7, 8, 9
            if ((mask & (1 << 6)) || (mask & (1 << 7)) || (mask & (1 << 8)) || (mask & (1 << 9))) {
                right = false;
            }

            bool middle = true;
            // Check 4, 5, 6, 7
            if ((mask & (1 << 4)) || (mask & (1 << 5)) || (mask & (1 << 6)) || (mask & (1 << 7))) {
                middle = false;
            }

            if (left && right) {
                max_families += 2;
            } else if (left || right || middle) {
                max_families += 1;
            }
        }

        return max_families;
    }
};

