#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = (int)s.size();
        vector<int> last(26, -1);

        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
        }

        vector<bool> used(26, false);
        string st;
        st.reserve(26);

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int idx = c - 'a';

            if (used[idx]) continue;

            while (!st.empty() && c < st.back() && last[st.back() - 'a'] > i) {
                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[idx] = true;
        }

        return st;
    }
};
