class Solution {
public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<int> adj[n];
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int par[n], coef[n];
        par[0] = -1;
        const function<void(int, int)> dfs = [&](int v, int p) {
            for (auto c : adj[v]) {
                if (c == p) continue;
                par[c] = v;
                dfs(c, v);
            }
        };
        dfs(0, 0);
        
        memset(coef, 0, sizeof(coef));
        for (auto t : trips) {
            int a = t[0], b = t[1];
            int tmp[n];
            memset(tmp, 0, sizeof(tmp));
            while (a != -1) {
                tmp[a]++;
                a = par[a];
            }
            bool buang = false;
            while (b != -1) {
                if (buang) {
                    tmp[b]--;
                } else if (tmp[b] == 1) {
                    buang = true;
                } else {
                    tmp[b]++;
                }
                b = par[b];
            }
            for (int i = 0; i < n; i++) {
                coef[i] += tmp[i];
            }
        }
        int val[n][2];
        const function<void(int, int)> dfs_val = [&](int v, int p) {
            val[v][0] = coef[v] * price[v];
            val[v][1] = coef[v] * (price[v] / 2);
            for (auto c : adj[v]) {
                if (c == p) continue;
                dfs_val(c, v);
                val[v][0] += min(val[c][0], val[c][1]);
                val[v][1] += val[c][0];
            }
        };
        dfs_val(0, 0);
        return min(val[0][0], val[0][1]);
    }
};