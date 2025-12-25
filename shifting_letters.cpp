#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.length();
        long long current_shift = 0;

        for (int i = n - 1; i >= 0; --i) {
            current_shift += shifts[i];
            current_shift %= 26;

            int original_pos = s[i] - 'a';
            int new_pos = (original_pos + current_shift) % 26;
            s[i] = 'a' + new_pos;
        }

        return s;
    }
};

