class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<int>> cnt(m, vector<int>(n));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        const function<void(vector<pair<int, int>>)> multiSourceBfs = [&] (vector<pair<int, int>> sources) -> void {
            queue<pair<int, int>> Q;
            vector<vector<bool>> vis(m, vector<bool>(n));
            for (auto source : sources) {
                vis[source.first][source.second] = true;
                Q.push(source);
            }
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = now.first + dir[i].first;
                    int ny = now.second + dir[i].second;
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                        continue;
                    }
                    if (heights[nx][ny] < heights[now.first][now.second]) continue;
                    if (vis[nx][ny]) continue;
                    vis[nx][ny] = true;
                    Q.emplace(nx, ny);
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cnt[i][j] += vis[i][j];
                }
            }
        };
        
        vector<pair<int, int>> pacificShore, atlanticShore;
        for (int i = 0; i < n; i++) pacificShore.emplace_back(0, i);
        for (int i = 1; i < m; i++) pacificShore.emplace_back(i, 0);
        for (int i = 0; i < n; i++) atlanticShore.emplace_back(m - 1, i);
        for (int i = 0; i < m - 1; i++) atlanticShore.emplace_back(i, n - 1);
        
        multiSourceBfs(pacificShore), multiSourceBfs(atlanticShore);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[i][j] == 2) {
                    res.emplace_back(vector<int>{i, j});
                }
            }
        }
        
        return res;
    }
};