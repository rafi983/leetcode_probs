#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = (int)s.size();
        int m = (int)p.size();
        int i = 0;
        int j = 0;
        int star = -1;
        int match = 0;

        while (i < n) {
            if (j < m && (p[j] == '?' || p[j] == s[i])) {
                ++i;
                ++j;
            } else if (j < m && p[j] == '*') {
                star = j;
                match = i;
                ++j;
            } else if (star != -1) {
                j = star + 1;
                ++match;
                i = match;
            } else {
                return false;
            }
        }

        while (j < m && p[j] == '*') {
            ++j;
        }

        return j == m;
    }
};
