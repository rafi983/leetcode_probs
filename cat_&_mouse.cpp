#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        int MOUSE_WIN = 1;
        int CAT_WIN = 2;
        int DRAW = 0;

        vector<vector<vector<int>>> color(n, vector<vector<int>>(n, vector<int>(3, 0)));
        vector<vector<vector<int>>> degree(n, vector<vector<int>>(n, vector<int>(3, 0)));

        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for (int neighbor : graph[c]) {
                    if (neighbor == 0) {
                        degree[m][c][2]--;
                    }
                }
            }
        }

        queue<vector<int>> q;

        // Initialize terminal states
        for (int c = 1; c < n; ++c) {
            for (int t = 1; t <= 2; ++t) {
                // Mouse at 0 -> Mouse wins
                color[0][c][t] = MOUSE_WIN;
                q.push({0, c, t, MOUSE_WIN});

                // Mouse at c -> Cat wins
                color[c][c][t] = CAT_WIN;
                q.push({c, c, t, CAT_WIN});
            }
        }

        while (!q.empty()) {
            vector<int> state = q.front();
            q.pop();
            int m = state[0];
            int c = state[1];
            int t = state[2];
            int result = state[3];

            // Find parents
            if (t == 1) {
                for (int prev_c : graph[c]) {
                    if (prev_c == 0) continue; // Cat cannot be at 0

                    if (color[m][prev_c][2] == DRAW) {
                        if (result == CAT_WIN) {
                            // Cat can move to a state that is CAT_WIN. So (m, prev_c, 2) is CAT_WIN.
                            color[m][prev_c][2] = CAT_WIN;
                            q.push({m, prev_c, 2, CAT_WIN});
                        } else if (result == MOUSE_WIN) {
                            // This move leads to MOUSE_WIN. Cat will avoid this if possible.
                            degree[m][prev_c][2]--;
                            if (degree[m][prev_c][2] == 0) {
                                color[m][prev_c][2] = MOUSE_WIN;
                                q.push({m, prev_c, 2, MOUSE_WIN});
                            }
                        }
                    }
                }
            } else {
                for (int prev_m : graph[m]) {
                    if (color[prev_m][c][1] == DRAW) {
                        if (result == MOUSE_WIN) {
                            // Mouse can move to a state that is MOUSE_WIN. So (prev_m, c, 1) is MOUSE_WIN.
                            color[prev_m][c][1] = MOUSE_WIN;
                            q.push({prev_m, c, 1, MOUSE_WIN});
                        } else if (result == CAT_WIN) {
                            // This move leads to CAT_WIN. Mouse will avoid this if possible.
                            degree[prev_m][c][1]--;
                            if (degree[prev_m][c][1] == 0) {
                                color[prev_m][c][1] = CAT_WIN;
                                q.push({prev_m, c, 1, CAT_WIN});
                            }
                        }
                    }
                }
            }
        }

        return color[1][2][1];
    }
};
