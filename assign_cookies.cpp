#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;
        int content = 0;

        while (i < (int)g.size() && j < (int)s.size()) {
            if (s[j] >= g[i]) {
                ++content;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }

        return content;
    }
};
