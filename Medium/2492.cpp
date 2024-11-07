class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n + 1);
        for (auto e : roads) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n + 1);
        const function<void(int)> dfs = [&](int x) -> void {
            for (auto c : adj[x]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };
        vis[1] = true;
        dfs(1);
        assert(vis[n]);
        int ans = INT_MAX;
        for (auto e : roads) {
            if (vis[e[0]]) {
                assert(vis[e[1]]);
                ans = min(ans, e[2]);
            }
        }
        return ans;
    }
};