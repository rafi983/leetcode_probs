#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.length() > 12 || s.length() < 4) return result;

        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (start == s.length()) {
                string ip = current[0] + "." + current[1] + "." + current[2] + "." + current[3];
                result.push_back(ip);
            }
            return;
        }

        for (int len = 1; len <= 3; ++len) {
            if (start + len > s.length()) break;

            string segment = s.substr(start, len);

            if (segment.length() > 1 && segment[0] == '0') continue;

            if (stoi(segment) > 255) continue;

            current.push_back(segment);
            backtrack(s, start + len, current, result);
            current.pop_back();
        }
    }
};
