class Solution {
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        vector<bool> is_prime(n + 1, true);
        is_prime[1] = false;
        for (int i = 2; i <= n; i++) {
            for (int j = i + i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
        vector<bool> processed(n);
        vector<int> sz(n), par(n);
        
        int timer = 0;
        vector<int> tin(n), tout(n), dis(n);
        const int B = 20;
        vector<vector<int>> up(n, vector<int>(B + 1));
        const function<void(int, int)> dfs_lca = [&](int v, int p) {
            tin[v] = timer++;
            up[v][0] = p;
            for (int i = 1; i <= B; i++) {
                up[v][i] = up[up[v][i - 1]][i - 1];
            }
            for (auto c : adj[v]) {
                if (c == p) continue;
                dis[c] = dis[v] + is_prime[c + 1];
                dfs_lca(c, v);
            }
            tout[v] = timer++;
        };
        const function<bool(int, int)> is_ancestor = [&](int a, int b) -> bool {
            return (tin[a] <= tin[b] && tout[a] >= tout[b]);
        };
        const function<int(int, int)> lca = [&](int u, int v) -> int {
            if (is_ancestor(u, v)) return u;
            if (is_ancestor(v, u)) return v;
            for (int i = B; i >= 0; i--) {
                if (!is_ancestor(up[u][i], v)) u = up[u][i];
            }
            return up[u][0];
        };
        const function<int(int, int)> DIS = [&](int a, int b) -> int {
            return dis[a] + dis[b] - 2 * dis[lca(a, b)] + is_prime[lca(a, b) + 1];
        };
        dfs_lca(0, 0);

        const function<void(int, int)> dfs_size = [&](int v, int p) {
            sz[v] = 1;
            for (auto c : adj[v]) {
                if (c == p || processed[c]) continue;
                dfs_size(c, v);
                sz[v] += sz[c];
            }
        };
        const function<int(int, int, int)> get_centroid = [&](int v, int p, int comp_size) -> int {
            for (auto c : adj[v]) {
                if (c == p || processed[c]) continue;
                if (sz[c] > (comp_size / 2)) return get_centroid(c, v, comp_size);
            }
            return v;
        };
        const function<void(int, int)> centroid_decomposition = [&](int v, int p) {
            dfs_size(v, p);
            int cur_sz = sz[v];
            int ctr = get_centroid(v, p, cur_sz);
            par[ctr] = (p == -1 ? ctr : p);
            processed[ctr] = true;
            for (auto c : adj[ctr]) {
                if (processed[c]) continue;
                centroid_decomposition(c, ctr);
            }
            processed[ctr] = false;
        };
        centroid_decomposition(0, -1);
        vector<vector<int>> child_dec(n);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (par[i] == i) continue;
            child_dec[par[i]].push_back(i);
        }
        vector<unordered_map<int, int>> cnt_dep(n), dep(n);
        const function<void(int, int, int, bool)> dfs_dec = [&](int par, int v, int p, bool filling) {
            for (auto c : child_dec[v]) {
                if (c == p) continue;
                if (filling) {
                    cnt_dep[par][dep[par][c]]++;
                } else {
                    dep[par][c] = DIS(c, par);
                    if (is_prime[par + 1]) {
                        if (dep[par][c] == 1) {
                            ans += cnt_dep[par][1];
                        }
                    } else {
                        if (dep[par][c] == 1) {
                            ans += cnt_dep[par][0];
                        } else if (dep[par][c] == 0) {
                            ans += cnt_dep[par][1];
                        }
                    }
                }
                dfs_dec(par, c, v, filling);
            }
        };
        for (int i = 0; i < n; i++) {
            dep[i][i] = is_prime[i + 1];
            long long tmp = ans;
            for (auto c : child_dec[i]) {
                // long long lmaoo = ans;
                //first add answer
                dep[i][c] = DIS(i, c);
                if (is_prime[i + 1]) {
                    if (dep[i][c] == 1) {
                        ans += cnt_dep[i][1];
                    }
                } else {
                    if (dep[i][c] == 1) {
                        ans += cnt_dep[i][0];
                    } else if (dep[i][c] == 0) {
                        ans += cnt_dep[i][1];
                    }
                }
                dfs_dec(i, c, i, false);
                //then fill count table
                cnt_dep[i][dep[i][c]]++;
                dfs_dec(i, c, i, true);
                // long long loll = ans - lmaoo;
            }
            ans += cnt_dep[i][1];
            // long long cur = ans - tmp;
            // cout << i << ' ' << cur << '\n';
        }

        return ans;
        
    }
};