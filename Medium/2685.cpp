class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        vector<int> cur_cc;
        const function<void(int)> dfs = [&](int v) {
            for (auto c : adj[v]) {
                if (vis[c]) continue;
                cur_cc.push_back(c);
                vis[c] = true;
                dfs(c);
            }
        };

        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            cur_cc.push_back(i);
            dfs(i);
            int sz = cur_cc.size();
            bool ok = true;
            for (auto v : cur_cc) {
                if (adj[v].size() != sz - 1) {
                    ok = false;
                    break;
                }
            }
            cur_cc.clear();
            ret += ok;
        }
        return ret;
    }
};