#include <vector>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        const int MAX_A = 1000;
        vector<int> freq(MAX_A, 0);

        for (int a : answers) {
            ++freq[a];
        }

        int total = 0;

        for (int x = 0; x < MAX_A; ++x) {
            int k = freq[x];
            if (!k) continue;

            int groupSize = x + 1;
            int groups = (k + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }

        return total;
    }
};
