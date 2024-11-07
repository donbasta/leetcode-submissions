class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> vis(m, vector<bool>(n));
        vector<pair<int, int>> dirs = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        };

        const function<void(int, int, bool)> flood_fill = [&](int x, int y, bool flipped) -> void {
            queue<pair<int, int>> Q;
            Q.emplace(x, y);
            vis[x][y] = true;
            if (flipped) board[x][y] = 'X';
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (auto dir : dirs) {
                    int nx = now.first + dir.first, ny = now.second + dir.second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (board[nx][ny] == 'X') continue;
                    if (vis[nx][ny]) continue;
                    Q.emplace(nx, ny);
                    vis[nx][ny] = true;
                    if (flipped) board[nx][ny] = 'X';
                }
            }
        };

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'X') continue;
            if (vis[i][0]) continue;
            flood_fill(i, 0, false);
        }
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'X') continue;
            if (vis[i][n - 1]) continue;
            flood_fill(i, n - 1, false);
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'X') continue;
            if (vis[0][i]) continue;
            flood_fill(0, i, false);
        }
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'X') continue;
            if (vis[m - 1][i]) continue;
            flood_fill(m - 1, i, false);
        }

        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (board[i][j] == 'X') continue;
                if (vis[i][j]) continue;
                flood_fill(i, j, true);
            }
        }
    }
};