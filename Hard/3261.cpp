class Solution {
public:
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& queries) {
        using ll = long long;
        int n = s.length();
        s.push_back('\0');
        int ri[n];
        int i0 = -1, i1 = -1;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            while (i0 < n && c0 <= k) {
                i0++; c0 += s[i0] == '0';
            }
            while (i1 < n && c1 <= k) {
                i1++, c1 += s[i1] == '1';
            }
            ri[i] = max(i0, i1) - 1;
            c0 -= s[i] == '0';
            c1 -= s[i] == '1';
        }
        ll pre[n];
        pre[0] = ri[0] - 0 + 1;
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (ri[i] - i + 1);
        }
        vector<ll> ans(queries.size());
        int itr = 0;
        for (auto q : queries) {
            int L = q[0], R = q[1];
            int u = upper_bound(ri + L, ri + R + 1, R) - ri;
            ll tmp = 0;
            tmp += 1ll * (R + 1 - u) * (R + 2 - u) / 2;
            if (u - 1 >= L) tmp += pre[u - 1] - (L ? pre[L - 1] : 0);
            ans[itr++] = tmp;
        }
        return ans;
    }
};