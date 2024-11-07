class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        set<pair<int, int>> se;
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            se.insert(make_pair(e[0], e[1]));
        }
        vector<int> ret(n);
        int lol = 0;
        const function<void(int, int)> dfs = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                if (se.count(make_pair(c, v))) lol++;
                dfs(c, v);
            }
        };
        const function<void(int, int)> dfs_reroot = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                int change = 1;
                if (se.count(make_pair(c, v))) {
                    change = -1;
                }
                ret[c] = ret[v] + change;
                dfs_reroot(c, v);
            }
        };
        dfs(0, 0);
        ret[0] = lol;
        dfs_reroot(0, 0);
        return ret;
    }
};