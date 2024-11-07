class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<int> ans(n), F(n);
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<pair<int, int>> se[n];
        function<void(int, int)> dfs = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs(c, v);
                se[v].emplace(F[c] + (2 - (c % 2)), c);
            }
            if (!se[v].empty()) {
                F[v] = se[v].rbegin()->first;
            }
        };

        function<void(int, int)> reroot = [&](int v, int p) {
            ans[v] = F[v];
            for (auto c : adj[v]) {
                if (c == p) continue;
    
                se[v].erase(make_pair(F[c] + (2 - (c % 2)), c));
                int tmp = 0;
                if (!se[v].empty()) tmp = se[v].rbegin()->first;
                se[c].emplace(tmp + (2 - (v % 2)), v);
                F[c] = se[c].rbegin()->first;

                reroot(c, v);

                se[c].erase(make_pair(tmp + (2 - (v % 2)), v));
                F[c] = 0;
                if (!se[c].empty()) F[c] = se[c].rbegin()->first;
                se[v].emplace(F[c] + (2 - (c % 2)), c);
            }
        };

        dfs(0, 0);
        reroot(0, 0);

        return ans;
    }
};