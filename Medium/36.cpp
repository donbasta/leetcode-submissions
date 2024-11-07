class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<bool> tmp(9);
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int dig = board[i][j] - '0';
                if (tmp[dig]) return false;
                tmp[dig] = true;
            }
        }
        for (int i = 0; i < 9; i++) {
            vector<bool> tmp(9);
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                int dig = board[j][i] - '0';
                if (tmp[dig]) return false;
                tmp[dig] = true;
            }
        }
        vector<int> ve = vector<int>{1, 4, 7};
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                vector<bool> tmp(9);
                for (int k = -1; k <= 1; k++) {
                    for (int l = -1; l <= 1; l++) {
                        if (board[ve[i] + k][ve[j] + l] == '.') continue;
                        int dig = board[ve[i] + k][ve[j] + l] - '0';
                        if (tmp[dig]) return false;
                        tmp[dig] = true;
                    }
                }
            }
        }
        return true;
    }
};