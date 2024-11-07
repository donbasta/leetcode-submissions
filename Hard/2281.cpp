class Solution {
public:
    int totalStrength(vector<int>& strength) {
        vector<pair<int, int>> tmp;
        int n = strength.size();
        int le[n], ri[n];
        memset(le, -1, sizeof(le));
        for (int i = 0; i < n; i++) ri[i] = n;
        for (int i = 0; i < n; i++) {
            while (!tmp.empty() && strength[i] < tmp.back().second) {
                ri[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, strength[i]);
        }
        tmp.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!tmp.empty() && strength[i] <= tmp.back().second) {
                le[tmp.back().first] = i;
                tmp.pop_back();
            }
            tmp.emplace_back(i, strength[i]);
        }
        int ans = 0;
        int pref[n], suf[n], cum_pref[n], cum_suf[n];
        memset(pref, 0, sizeof(pref));
        memset(suf, 0, sizeof(suf));
        memset(cum_pref, 0, sizeof(cum_pref));
        memset(cum_suf, 0, sizeof(cum_suf));
        const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            pref[i] = ((i ? pref[i - 1] : 0) + strength[i]) % MOD;
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = ((i < n - 1 ? suf[i + 1] : 0) + strength[i]) % MOD;
        }
        for (int i = 0; i < n; i++) {
            cum_pref[i] = ((i ? cum_pref[i - 1] : 0) + pref[i]) % MOD;
        }
        for (int i = n - 1; i >= 0; i--) {
            cum_suf[i] = ((i < n - 1 ? cum_suf[i + 1] : 0) + suf[i]) % MOD;
        }        
        const function<int(int, int)> get_kir = [&](int a, int b) -> int { //a >= b
            int ret = (cum_suf[b] - (a < n - 1 ? cum_suf[a + 1] : 0)) % MOD;
            ret = (1ll * ret - 1ll * (a < n - 1 ? suf[a + 1] : 0) * (a - b + 1)) % MOD;
            if (ret < 0) ret += MOD;
            return ret;
        };
        const function<int(int, int)> get_kan = [&](int a, int b) -> int { //a <= b
            int ret = (cum_pref[b] - (a ? cum_pref[a - 1] : 0)) % MOD;
            ret = (1ll * ret - 1ll * (a ? pref[a - 1] : 0) * (b - a + 1)) % MOD;
            if (ret < 0) ret += MOD;
            return ret;
        };
        for (int i = 0; i < n; i++) {
            int L = le[i] + 1, R = ri[i] - 1;
            int kan = R - i + 1, kir = i - L + 1;
            int sum_kir = get_kir(i - 1, L);
            int sum_kan = get_kan(i + 1, R);
            int tot = (1ll * strength[i] * kan * kir + 1ll * sum_kir * kan + 1ll * sum_kan * kir) % MOD;
            ans = (1ll * ans + 1ll * strength[i] * tot) % MOD;
        }
        return ans;
    }
};