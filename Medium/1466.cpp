class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> se;
        for (auto c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
            se.emplace(c[0], c[1]);
        }
        int ans = 0;
        vector<bool> vis(n);
        const function<void(int)> dfs = [&](int v) -> void {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                if (!se.count(make_pair(c, v))) ans++;
                dfs(c);
            }
        };
        vis[0] = true;
        dfs(0);
        return ans;
    }
};