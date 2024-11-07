class Solution {
public:
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            adj[prevRoom[i]].push_back(i);
        }
        vector<int> fc(n), sz(n, 1), ifc(n);
        const int MOD = 1e9 + 7;
        fc[0] = 1;
        for (int i = 1; i < n; i++) fc[i] = (1ll * fc[i - 1] * i) % MOD;
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        ifc[n - 1] = fpow(fc[n - 1], MOD - 2);
        for (int i = n - 2; i >= 0; i--) ifc[i] = (1ll * (i + 1) * ifc[i + 1]) % MOD;
        const function<int(int)> dfs = [&](int v) -> int {
            int tmp = 1;
            for (auto c : adj[v]) {
                tmp = (1ll * tmp * dfs(c)) % MOD;
                tmp = (1ll * tmp * ifc[sz[c]]) % MOD;
                sz[v] += sz[c];
            }
            return (1ll * tmp * fc[sz[v] - 1]) % MOD;
        };
        return dfs(0);
    }
};