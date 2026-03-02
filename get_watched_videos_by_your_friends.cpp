#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(const vector<vector<string>>& watchedVideos,
                                          const vector<vector<int>>& friends,
                                          int id,
                                          int level) {
        int n = static_cast<int>(friends.size());
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(id);
        dist[id] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (dist[cur] == level) {
                continue;
            }
            for (int nei : friends[cur]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[cur] + 1;
                    q.push(nei);
                }
            }
        }

        unordered_map<string, int> freq;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == level) {
                for (const string& v : watchedVideos[i]) {
                    ++freq[v];
                }
            }
        }

        vector<pair<string, int>> items;
        items.reserve(freq.size());
        for (const auto& it : freq) {
            items.push_back(it);
        }

        sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second < b.second;
            }
            return a.first < b.first;
        });

        vector<string> result;
        result.reserve(items.size());
        for (const auto& it : items) {
            result.push_back(it.first);
        }
        return result;
    }
};
