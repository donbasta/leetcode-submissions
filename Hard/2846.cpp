#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

class Solution {
public:    
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        const int B = 14;
        int tin[n], tout[n];
        int up[n][B];
        memset(up, 0, sizeof(up));
        int timer = 0;
        vector<int> adj[n];
        int dep[n];
        dep[0] = 0;
        map<pair<int, int>, int> wei;
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            e[2]--;
            wei[make_pair(e[0], e[1])] = e[2];
            wei[make_pair(e[1], e[0])] = e[2];
        }
        int cnt[26][n];
        for (int i = 0; i < 26; i++) cnt[i][0] = 0;
        const function<void(int, int)> dfs = [&](int v, int p) -> void {
            tin[v] = ++timer;
            up[v][0] = p;
            for (int i = 1; i < B; i++) up[v][i] = up[up[v][i - 1]][i - 1];
            for (int i = 0; i < 26; i++) {
                cnt[i][v] = cnt[i][p] + (wei[make_pair(v, p)] == i);
            }
            for (int c : adj[v]) {
                if (c == p) continue;
                dep[c] = dep[v] + 1;
                dfs(c, v);
            }
            tout[v] = ++timer;
        };
        const function<bool(int, int)> is_ancestor = [&](int u, int v) -> bool {
            return tin[u] <= tin[v] && tout[u] >= tout[v];
        };
        const function<int(int, int)> LCA = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            for (int i = B - 1; i >= 0; i--) {
                if (!is_ancestor(up[u][i], v)) u = up[u][i];
            }
            return up[u][0];
        };
        dfs(0, 0);
        
        int sz = queries.size();
        vector<int> ans(sz);
        for (int i = 0; i < sz; i++) {
            int lca = LCA(queries[i][0], queries[i][1]);
            int mx = 0;
            int dis = dep[queries[i][0]] + dep[queries[i][1]] - 2 * dep[lca];
            for (int j = 0; j < 26; j++) {
                mx = max(mx, cnt[j][queries[i][0]] + cnt[j][queries[i][1]] - 2 * cnt[j][lca]);
            }
            ans[i] = dis - mx;
        }
        return ans;
    }
};