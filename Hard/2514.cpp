class Solution {
public:
    const int mod = 1e9 + 7;

    int fpow (int a, int b) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1ll * ret * a) % mod;
            a = (1ll * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }

    int countAnagrams(string s) {
        int n = 1e5;
        vector<int> fc(n + 1), ifc(n + 1);
        fc[0] = 1;
        for (int i = 1; i <= n; i++) {
            fc[i] = (1ll * fc[i - 1] * i) % mod;
        }
        ifc[n] = fpow(fc[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            ifc[i] = (1ll * ifc[i + 1] * (i + 1)) % mod;
        }
        vector<int> cnt(26);
        int ans = 1;
        int tot = 0;
        for (auto c : s) {
            if (c == ' ') {
                int perm = fc[tot];
                for (int i = 0; i < 26; i++) {
                    perm = (1ll * perm * ifc[cnt[i]]) % mod;
                }
                ans = (1ll * ans * perm) % mod;
                tot = 0;
                for (int i = 0; i < 26; i++) cnt[i] = 0;
            } else {
                tot++;
                cnt[c - 'a']++;
            }
        }
        int perm = fc[tot];
        for (int i = 0; i < 26; i++) {
            perm = (1ll * perm * ifc[cnt[i]]) % mod;
        }
        ans = (1ll * ans * perm) % mod;
        return ans;
    }
};