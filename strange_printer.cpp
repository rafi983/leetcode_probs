#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int strangePrinter(std::string s) {
        int n = s.length();
        if (n == 0) return 0;

        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + 1;
                for (int k = i; k < j; k++) {
                    if (s[k] == s[j]) {
                        dp[i][j] = std::min(dp[i][j], dp[i][k] + (k + 1 <= j - 1 ? dp[k + 1][j - 1] : 0));
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};

