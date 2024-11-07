class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<pair<int, int>> adj[m * n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int cur = i * n + j;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir[k].first, nj = j + dir[k].second;
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    int nx = ni * n + nj;
                    int w = 1;
                    if (k + 1 == grid[i][j]) w = 0;
                    adj[cur].emplace_back(nx, w);
                }
            }
        }
        deque<int> D;
        int dis[m * n];
        for (int i = 0; i < m * n; i++) dis[i] = INT_MAX;
        D.push_front(0);
        dis[0] = 0;
        while (!D.empty()) {
            auto now = D.front();
            D.pop_front();
            for (auto e : adj[now]) {
                int u = e.first, w = e.second;
                if (dis[now] + w < dis[u]) {
                    dis[u] = dis[now] + w;
                    if (w == 1) {
                        D.push_back(u);
                    } else {
                        D.push_front(u);
                    }
                }
            }
        }
        return dis[m * n - 1];
    }
};