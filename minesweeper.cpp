#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r = click[0];
        int c = click[1];

        if (board[r][c] == 'M') {
            board[r][c] = 'X';
            return board;
        }

        int m = board.size();
        int n = board[0].size();

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        if (board[r][c] == 'E') {
            int mineCount = 0;
            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    if (board[nr][nc] == 'M') {
                        mineCount++;
                    }
                }
            }

            if (mineCount > 0) {
                board[r][c] = mineCount + '0';
            } else {
                board[r][c] = 'B';
                for (int i = 0; i < 8; ++i) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (board[nr][nc] == 'E') {
                            vector<int> nextClick = {nr, nc};
                            updateBoard(board, nextClick);
                        }
                    }
                }
            }
        }

        return board;
    }
};
