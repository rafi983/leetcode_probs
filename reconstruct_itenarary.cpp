#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        for (auto& entry : adj) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        vector<string> route;
        route.reserve(tickets.size() + 1);
        dfs("JFK", adj, route);
        reverse(route.begin(), route.end());
        return route;
    }

private:
    void dfs(const string& airport, unordered_map<string, vector<string>>& adj, vector<string>& route) {
        vector<string>& destinations = adj[airport];
        while (!destinations.empty()) {
            string nextAirport = destinations.back();
            destinations.pop_back();
            dfs(nextAirport, adj, route);
        }
        route.push_back(airport);
    }
};
