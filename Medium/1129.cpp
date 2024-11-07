class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> blue(n), red(n);
        for (auto e : redEdges) {
            red[e[0]].push_back(e[1]);
        }
        for (auto e : blueEdges) {
            blue[e[0]].push_back(e[1]);
        }

        const int INF = 2e9;
        vector<vector<int>> ans(n, vector<int>(2, INF));
        ans[0][0] = ans[0][1] = 0;
        const auto bfs = [&](int col) -> void {
            queue<pair<int, int>> Q;
            Q.emplace(0, col);
            vector<vector<bool>> vis(n, vector<bool>(2));
            vis[0][col] = true;
            while (!Q.empty()) {
                auto now = Q.front();
                Q.pop();
                vector<int> adj = (now.second ? blue[now.first]: red[now.first]);
                for (auto ne : adj) {
                    if (vis[ne][now.second ^ 1]) continue;
                    ans[ne][now.second ^ 1] = min(ans[ne][now.second ^ 1], ans[now.first][now.second] + 1);
                    vis[ne][now.second ^ 1] = true;
                    Q.emplace(ne, now.second ^ 1);
                }
            }
        };

        bfs(0), bfs(1);
        vector<int> ret(n);
        for (int i = 0; i < n; i++) {
            ret[i] = min(ans[i][0], ans[i][1]);
            if (ret[i] == INF) ret[i] = -1;
        }
        return ret;
    }
};