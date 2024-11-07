class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        for (auto& r : row) r /= 2;
        int n = row.size() / 2;
        vector<vector<int>> pos(n), adj(n);
        for (int i = 0; i < n * 2; i++) {
            pos[row[i]].push_back(i / 2);
        }
        for (int i = 0; i < n; i++) {
            adj[pos[i][0]].push_back(pos[i][1]);
            adj[pos[i][1]].push_back(pos[i][0]);
        }
        vector<bool> vis(n);
        function<void(int)> dfs = [&](int v) {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                vis[c] = true;
                dfs(c);
            }
        };
        int cc = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            cc++;
            vis[i] = true;
            dfs(i);
        }
        return n - cc;
    }
};