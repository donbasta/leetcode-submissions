class Solution {
public:
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (!valid(i, j, k, board)) continue;
                    board[i][j] = k;
                    if (backtrack(board)) return true;
                    else board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }

    bool valid(int r, int c, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) if (board[r][i] == val) return false;
        for (int i = 0; i < 9; i++) if (board[i][c] == val) return false;
        for (int i = 0; i < 9; i++) if (board[3 * (r / 3) + i / 3][3 * (c / 3) + (i % 3)] == val) return false;
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};