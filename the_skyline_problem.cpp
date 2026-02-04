#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector<pair<int, int>> events;
        for (const auto& b : buildings) {
            events.push_back({b[0], -b[2]}); // Start
            events.push_back({b[1], b[2]});  // End
        }

        sort(events.begin(), events.end());

        vector<vector<int>> result;
        multiset<int> heights;
        heights.insert(0); // Ground level
        int prevMax = 0;

        for (const auto& event : events) {
            int x = event.first;
            int h = event.second;

            if (h < 0) {
                heights.insert(-h);
            } else {
                heights.erase(heights.find(h));
            }

            int currentMax = *heights.rbegin();
            if (currentMax != prevMax) {
                result.push_back({x, currentMax});
                prevMax = currentMax;
            }
        }

        return result;
    }
};
