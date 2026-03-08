#include <cassert>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        string start(max(0, n - 1), '0');
        string sequence;
        sequence.reserve(power(k, n));

        unordered_set<string> visited;
        visited.reserve(power(k, n) * 2);
        dfs(start, k, visited, sequence);

        return sequence + start;
    }

private:
    int power(int base, int exponent) {
        int result = 1;
        while (exponent-- > 0) {
            result *= base;
        }
        return result;
    }

    void dfs(const string& node, int k, unordered_set<string>& visited, string& sequence) {
        for (int digit = 0; digit < k; ++digit) {
            char nextDigit = static_cast<char>('0' + digit);
            string edge = node + nextDigit;
            if (visited.insert(edge).second) {
                string nextNode = edge.substr(1);
                dfs(nextNode, k, visited, sequence);
                sequence.push_back(nextDigit);
            }
        }
    }
};
