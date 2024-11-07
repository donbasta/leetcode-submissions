class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        const int MX = 1e4;
        vector<vector<int>> adj(2 * MX + 2);
        for (auto e : stones) {
            adj[e[0]].push_back(e[1] + MX + 1);
            adj[e[1] + MX + 1].push_back(e[0]);
        }
        vector<bool> vis(2 * MX + 2);
        int sisa = 0;
        const function<void(int)> dfs = [&](int v) -> void {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };
        for (int i = 0; i <= MX; i++) {
            if (adj[i].empty()) continue;
            if (vis[i]) continue;
            sisa++;
            vis[i] = true;
            dfs(i);
        }
        return (int) stones.size() - sisa;
    }
};