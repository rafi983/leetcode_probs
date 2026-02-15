#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int containVirus(vector<vector<int>>& isInfected) {
        int m = isInfected.size();
        int n = isInfected[0].size();
        int totalWalls = 0;

        while (true) {
            vector<set<pair<int, int>>> regions;
            vector<set<pair<int, int>>> frontiers;
            vector<int> perimeters;

            vector<vector<bool>> visited(m, vector<bool>(n, false));

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 1 && !visited[i][j]) {
                        regions.push_back({});
                        frontiers.push_back({});
                        perimeters.push_back(0);

                        dfs(isInfected, visited, i, j, regions.back(), frontiers.back(), perimeters.back());
                    }
                }
            }

            if (regions.empty()) break;

            int maxThreatIdx = -1;
            int maxThreatCount = -1;

            for (int i = 0; i < regions.size(); ++i) {
                if ((int)frontiers[i].size() > maxThreatCount) {
                    maxThreatCount = frontiers[i].size();
                    maxThreatIdx = i;
                }
            }

            if (maxThreatCount == 0) break; // No more uninfected cells to infect

            totalWalls += perimeters[maxThreatIdx];

            for (auto& cell : regions[maxThreatIdx]) {
                isInfected[cell.first][cell.second] = 2;
            }

            for (int i = 0; i < regions.size(); ++i) {
                if (i == maxThreatIdx) continue;
                for (auto& cell : frontiers[i]) {
                    isInfected[cell.first][cell.second] = 1;
                }
            }
        }

        return totalWalls;
    }

private:
    void dfs(vector<vector<int>>& isInfected, vector<vector<bool>>& visited, int r, int c,
             set<pair<int, int>>& region, set<pair<int, int>>& frontier, int& perimeter) {
        int m = isInfected.size();
        int n = isInfected[0].size();

        visited[r][c] = true;
        region.insert({r, c});

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                if (isInfected[nr][nc] == 1) {
                    if (!visited[nr][nc]) {
                        dfs(isInfected, visited, nr, nc, region, frontier, perimeter);
                    }
                } else if (isInfected[nr][nc] == 0) {
                    frontier.insert({nr, nc});
                    perimeter++;
                }
            }
        }
    }
};

