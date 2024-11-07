class Solution {
public:
    int makeStringSorted(string s) {
        vector<int> cnt(26);
        for (auto c : s) cnt[c - 'a']++;
        int n = s.length();
        const int MOD = 1e9 + 7;
        int ord = 0;

        auto fpow = [&](int x, int y) -> int {
            int ret = 1;
            while (y) {
                if (y & 1) ret = (1ll * ret * x) % MOD;
                x = (1ll * x * x) % MOD;
                y >>= 1;
            }
            return ret;
        };

        const int M = 3000;
        int fc[M + 5], ifc[M + 5];
        fc[0] = 1;
        for (int i = 1; i <= M; i++) fc[i] = (1ll * fc[i - 1] * i) % MOD;
        ifc[M] = fpow(fc[M], MOD - 2);
        for (int i = M - 1; i >= 0; i--) ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % MOD;

        for (int i = 0; i < n; i++) {
            int cur = s[i] - 'a';
            for (int j = 0; j < cur; j++) {
                if (cnt[j] > 0) {
                    cnt[j]--;
                    int ret = fc[n - 1 - i];
                    for (int k = 0; k < 26; k++) {
                        ret = (1ll * ret * ifc[cnt[k]]) % MOD;
                    }
                    ord = (ord + ret) % MOD;
                    cnt[j]++;
                }
            }
            cnt[cur]--;
        }
        return ord;
    }
};