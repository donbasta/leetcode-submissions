class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }

        vector<int> ret(n), chd(n);
        const function<void(int, int)> dfs = [&](int v, int p) -> void {
            chd[v] = 1;
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                chd[v] += chd[c];
            }
        };
        dfs(0, 0);

        int cur = accumulate(chd.begin(), chd.end(), 0) - n;
        const function<void(int, int)> dfs2 = [&](int v, int p) -> void {
            ret[v] = cur;
            for (auto c : adj[v]) {
                if (c == p) continue;
                int k = n - chd[c];
                cur = (cur + n - 2 * chd[c]);
                dfs2(c, v);
                cur = (cur - n + 2 * chd[c]);
            }
        };
        dfs2(0, 0);
        return ret;
    }
};