class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {0, 1, -1, 1, -1, 0, 1, -1};

        vector<vector<int>> tmp = board;
        int m = tmp.size();
        int n = tmp[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int live = 0;
                for (int k = 0; k < 8; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    live += board[ni][nj] == 1;
                }
                if (board[i][j] == 1) {
                    if (live < 2) tmp[i][j] = 0;
                    else if (live <= 3) tmp[i][j] = 1;
                    else if (live > 3) tmp[i][j] = 0;
                } else {
                    if (live == 3) tmp[i][j] = 1;
                    else tmp[i][j] = 0;
                }
            }
        }
        board = tmp;
    }
};