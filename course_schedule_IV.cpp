#include <bitset>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                    const vector<vector<int>>& prerequisites,
                                    const vector<vector<int>>& queries) {
        const int MAXN = 100;
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (const auto& p : prerequisites) {
            int u = p[0];
            int v = p[1];
            graph[u].push_back(v);
            ++indegree[v];
        }

        vector<bitset<MAXN>> prereq(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : graph[u]) {
                prereq[v] |= prereq[u];
                prereq[v].set(u);
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        vector<bool> answer;
        answer.reserve(queries.size());
        for (const auto& qv : queries) {
            int u = qv[0];
            int v = qv[1];
            answer.push_back(prereq[v].test(u));
        }
        return answer;
    }
};