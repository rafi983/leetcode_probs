#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xorSum = 0;
        for (int num : nums) {
            xorSum ^= num;
        }

        if (xorSum == 0) {
            return true;
        }

        return nums.size() % 2 == 0;
    }
};
