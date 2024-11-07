class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> ret(n);
        vector<vector<int>> cnt(26, vector<int>(n));
        const function<void(int, int)> dfs = [&](int v, int p) -> void {
            cnt[labels[v] - 'a'][v] = 1;
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                for (int i = 0; i < 26; i++) {
                    cnt[i][v] += cnt[i][c];
                }
            }
            ret[v] = cnt[labels[v] - 'a'][v];
        };
        dfs(0, 0);
        return ret;
    }
};