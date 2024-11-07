class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        for (int i = 0;  i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int B = 0, W = 0;
                for (int ii = 0; ii < 2; ii++) {
                    for (int jj = 0; jj < 2; jj++) {
                        B += grid[i + ii][j + jj] == 'B';
                        W += grid[i + ii][j + jj] == 'W';
                    }
                }
                if (B >= 3 || W >= 3) {
                    return true;
                }
            }
        }
        return false;
    }
};