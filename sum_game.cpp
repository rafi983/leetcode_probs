#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int sumL = 0, sumR = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') {
                qL++;
            } else {
                sumL += num[i] - '0';
            }
        }

        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') {
                qR++;
            } else {
                sumR += num[i] - '0';
            }
        }

        if ((qL + qR) % 2 != 0) {
            return true;
        }

        int diff = sumL - sumR;
        int qDiff = qL - qR;

        return (2 * diff + 9 * qDiff) != 0;
    }
};


