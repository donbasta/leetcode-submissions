class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto e : edges) adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);
        vector<int> sz(n);

        int ret = 0;
        function<void(int, int)> dfs = [&](int v, int p) {
            int x = -1;
            bool ok = true;
            sz[v] = 1;
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                if (x == -1) x = sz[c];
                else {
                    if (sz[c] != x) ok = false;
                }
                sz[v] += sz[c];
            }
            ret += ok;
        };
        dfs(0, 0);
        return ret;
    }
};