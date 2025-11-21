#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int total = 0;

        total += m * (1 << (n - 1));

        for (int c = 1; c < n; ++c) {
            int ones = 0;

            for (int r = 0; r < m; ++r) {
                int val = grid[r][c];
                if (grid[r][0] == 0) {
                    val ^= 1;
                }
                if (val == 1) {
                    ++ones;
                }
            }

            int maxOnes = max(ones, m - ones);
            int bitValue = 1 << (n - 1 - c);
            total += maxOnes * bitValue;
        }

        return total;
    }
};

#ifdef MATRIX_SCORE_TEST
#include <iostream>

int main() {
    Solution sol;

    vector<vector<int>> g1{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    cout << sol.matrixScore(g1) << "\n";

    vector<vector<int>> g2{{0}};
    cout << sol.matrixScore(g2) << "\n";

    return 0;
}
#endif
