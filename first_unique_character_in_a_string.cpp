#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Frequency array for lowercase English letters
        int count[26] = {0};

        // First pass: count frequencies
        for (char c : s) {
            count[c - 'a']++;
        }

        // Second pass: find the first character with count 1
        for (int i = 0; i < s.length(); i++) {
            if (count[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
