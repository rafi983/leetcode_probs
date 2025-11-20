#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n <= 1) return s;

        int bestStart = 0, bestLen = 1;

        for (int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            int start = l + 1, len = r - l - 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = start;
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                --l;
                ++r;
            }
            start = l + 1;
            len = r - l - 1;
            if (len > bestLen) {
                bestLen = len;
                bestStart = start;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};
