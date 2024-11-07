class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        bool exit[m][n];
        memset(exit, false, sizeof(exit));
        for (int i = 0; i < n; i++) {
            if (maze[0][i] == '.') exit[0][i] = true;
            if (maze[m - 1][i] == '.') exit[m - 1][i] = true;
        }
        for (int i = 0; i < m; i++) {
            if (maze[i][0] == '.') exit[i][0] = true;
            if (maze[i][n - 1] == '.') exit[i][n - 1] = true;
        }
        exit[entrance[0]][entrance[1]] = false;
        queue<pair<int, int>> Q;
        const int INF = 2e9;
        vector<vector<int>> dis(m, vector<int>(n, INF));
        dis[entrance[0]][entrance[1]] = 0;
        Q.emplace(entrance[0], entrance[1]);
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        while (!Q.empty()) {
            auto now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = now.first + dx[i], nc = now.second + dy[i];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (maze[nr][nc] == '+') continue;
                if (dis[nr][nc] != INF) continue;
                dis[nr][nc] = dis[now.first][now.second] + 1;
                Q.emplace(nr, nc);
            }
        }

        int ans = INF;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!exit[i][j]) continue;
                // cout << i << ' ' << j << ' ' << dis[i][j] << '\n';
                ans = min(ans, dis[i][j]);
            }
        }
        if (ans == INF) return -1;
        return ans;
    }
};