class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        const int INF = 2e9;
        vector<vector<int>> dis(m * n, vector<int>(m * n, INF));

        auto id = [&](int r, int c) -> int {
            return n * r + c;
        };

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] == 0) continue;
                int cur = id(i, j);
                vector<bool> vis(m * n);
                dis[cur][cur] = 0;
                vis[cur] = true;
                queue<int> Q;
                Q.emplace(cur);
                while (!Q.empty()) {
                    auto now = Q.front();
                    Q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nr = (now / n) + dx[k], nc = (now % n) + dy[k];
                        if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                        if (forest[nr][nc] == 0) continue;
                        if (vis[id(nr, nc)]) continue;
                        vis[id(nr, nc)] = true;
                        dis[cur][id(nr, nc)] = dis[cur][now] + 1;
                        Q.emplace(id(nr, nc)); 
                    }
                }
            }
        }
        vector<pair<int, int>> trees;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(forest[i][j], id(i, j));
                }
            }
        }
        sort(trees.begin(), trees.end());
        int sz = trees.size();
        if (dis[0][trees[0].second] == INF) return -1;
        int ans = dis[0][trees[0].second];
        for (int i = 1; i < sz; i++) {
            if (dis[trees[i - 1].second][trees[i].second] == INF) return -1;
            ans += dis[trees[i - 1].second][trees[i].second];
        }
        return ans;
    }
};