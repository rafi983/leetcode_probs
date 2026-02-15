#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (size_t i = 0; i < equations.size(); ++i) {
            const string& u = equations[i][0];
            const string& v = equations[i][1];
            double val = values[i];

            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }

        vector<double> results;
        for (const auto& query : queries) {
            const string& start = query[0];
            const string& end = query[1];

            if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) {
                results.push_back(-1.0);
            } else if (start == end) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(start, end, visited, adj);
                results.push_back(result);
            }
        }

        return results;
    }

private:
    double dfs(const string& current, const string& target, unordered_set<string>& visited, unordered_map<string, vector<pair<string, double>>>& adj) {
        if (current == target) {
            return 1.0;
        }

        visited.insert(current);

        for (const auto& neighbor : adj[current]) {
            const string& nextNode = neighbor.first;
            double value = neighbor.second;

            if (visited.find(nextNode) == visited.end()) {
                double subResult = dfs(nextNode, target, visited, adj);
                if (subResult != -1.0) {
                    return value * subResult;
                }
            }
        }

        return -1.0;
    }
};

