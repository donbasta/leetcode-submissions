class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> chd(n);
        for (int i = 0; i < n; i++) {
            if (i == 0) continue;
            chd[parent[i]].push_back(i);
        }
        vector<bool> ret(n);
        vector<int> A(n), B(n), sz(n), pw(n + 1);
        const int mod = 1e9 + 7;
        const int base = 37;
        pw[0] = 1;
        for (int i = 1; i <= n; i++) pw[i] = (1ll * pw[i - 1] * base) % mod;
        function<void(int)> dfs = [&](int v) {
            int a = 0, b = 0;
            sz[v] = 1;
            vector<pair<int, int>> tmp; 
            for (auto c : chd[v]) {
                dfs(c);
                sz[v] += sz[c];
                a = ((1ll * a * pw[sz[c]]) + A[c]) % mod;
                tmp.emplace_back(B[c], c);
            }
            reverse(tmp.begin(), tmp.end());
            b = (s[v] - 'a' + 1) % mod;
            for (auto t : tmp) {
                b = ((1ll * b * pw[sz[t.second]]) + t.first) % mod;
            }
            a = (1ll * a * pw[1] + (s[v] - 'a' + 1)) % mod;
            A[v] = a, B[v] = b;
            ret[v] = (a == b);
        };
        dfs(0);
        return ret;
    }
};