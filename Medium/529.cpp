class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m = board.size();
        int n = board[0].size();
        bool clicked[m][n];
        memset(clicked, 0, sizeof(clicked));
        int r = click[0], c = click[1];
        queue<pair<int, int>> Q;
        Q.emplace(r, c);
        clicked[r][c] = true;

        int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
        int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            int cr = now.first, cc = now.second;
            if (board[cr][cc] == 'M') {
                board[cr][cc] = 'X';
                return board;
            }
            int cnt = 0;
            for (int i = 0; i < 8; i++) {
                int nr = cr + dx[i], nc = cc + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                cnt += board[nr][nc] == 'M';
            }
            if (cnt == 0) {
                for (int i = 0; i < 8; i++) {
                    int nr = cr + dx[i], nc = cc + dy[i];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (clicked[nr][nc]) continue;
                    clicked[nr][nc] = true;
                    Q.emplace(nr, nc);
                }
                board[cr][cc] = 'B';
            } else {
                board[cr][cc] = (char)(cnt + '0');
            }
        }
        return board;
    }
};