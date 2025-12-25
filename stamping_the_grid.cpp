#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> P(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                P[i + 1][j + 1] = P[i][j + 1] + P[i + 1][j] - P[i][j] + grid[i][j];
            }
        }

        vector<vector<int>> diff(m + 2, vector<int>(n + 2, 0));

        for (int i = 0; i <= m - stampHeight; ++i) {
            for (int j = 0; j <= n - stampWidth; ++j) {
                // Check if the stamp region starting at (i, j) is empty
                // Bottom-right of stamp is (i + stampHeight - 1, j + stampWidth - 1)
                int r2 = i + stampHeight;
                int c2 = j + stampWidth;

                // Sum of region in grid using prefix sums
                int sum = P[r2][c2] - P[i][c2] - P[r2][j] + P[i][j];

                if (sum == 0) {
                    // Valid stamp position, mark it in difference array
                    // The stamp covers grid[i..r2-1][j..c2-1]
                    // In 1-based diff array, this corresponds to diff[i+1..r2][j+1..c2]
                    diff[i + 1][j + 1]++;
                    diff[i + 1][c2 + 1]--;
                    diff[r2 + 1][j + 1]--;
                    diff[r2 + 1][c2 + 1]++;
                }
            }
        }

        // 3. Compute prefix sum of the difference array to get actual coverage counts
        vector<vector<int>> coverage(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                coverage[i][j] = coverage[i - 1][j] + coverage[i][j - 1] - coverage[i - 1][j - 1] + diff[i][j];

                // Check if empty cell is covered
                // grid[i-1][j-1] corresponds to coverage[i][j]
                if (grid[i - 1][j - 1] == 0 && coverage[i][j] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};

