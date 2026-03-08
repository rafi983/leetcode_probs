#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = static_cast<int>(row.size());
        vector<int> position(n);
        for (int i = 0; i < n; ++i) {
            position[row[i]] = i;
        }

        int swaps = 0;
        for (int i = 0; i < n; i += 2) {
            int firstPerson = row[i];
            int partner = firstPerson ^ 1;

            if (row[i + 1] == partner) {
                continue;
            }

            int partnerIndex = position[partner];
            int secondPerson = row[i + 1];

            swap(row[i + 1], row[partnerIndex]);
            position[secondPerson] = partnerIndex;
            position[partner] = i + 1;
            swaps++;
        }

        return swaps;
    }
};