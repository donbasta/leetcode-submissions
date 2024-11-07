class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        using ll = long long;
        const ll MOD = 1e9 + 7;
        auto fpow = [&](ll a, ll b) -> ll {
            ll ret = 1;
            while (b) {
                if (b & 1) ret = ret * a % MOD;
                a = a * a % MOD;
                b >>= 1;
            }
            return ret;
        };

        vector<ll> fc(n + 1), ifc(n + 1);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) fc[i] = fc[i - 1] * i % MOD;
        ifc[n] = fpow(fc[n], MOD - 2);
        for (int i = n - 1; i >= 0; i--) ifc[i] = ifc[i + 1] * (i + 1) % MOD;

        int sz = sick.size();
        ll res = fc[n - sz];
        for (int i = 0; i < sz; i++) {
            if (sick[i] == 0) continue;
            if (i == 0) {
                res = (res * ifc[sick[i]]) % MOD;
            } else {
                int cnt = sick[i] - sick[i - 1] - 1;
                if (cnt == 0) continue;
                res = (res * fpow(cnt, MOD - 2)) % MOD;
                ll tmp = 0;
                for (int j = 0; j <= cnt - 1; j++) {
                    tmp = (tmp + ifc[j] * ifc[cnt - 1 - j]) % MOD;
                }
                res = (res * tmp) % MOD;
            }
        }
        if (sick.back() < n - 1) {
            res = (res * ifc[n - 1 - sick.back()]) % MOD;
        }
        res %= MOD;
        if (res < 0) res += MOD;
        return res;
    }
};