class Solution {
public:
    string longestDupSubstring(string s) {
        int n = s.length();
        vector<vector<int>> pw(n, vector<int>(2));
        const int B[2] = {31, 37};
        const int MOD[2] = {998244353, 1000000009};
        pw[0][0] = pw[0][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                pw[i][j] = (1ll * pw[i - 1][j] * B[j]) % MOD[j];
            }
        }
        int l = 1, r = n - 1, piv = 0;
        string ret = "";

        auto f = [&](int a, int b) -> long long {
            return ((1ll << 32) * a + b);
        };

        while (l <= r) {
            int mid = (l + r) >> 1;
            unordered_map<long long, bool> ada;
            bool ok = false;
            int cur[2] = {0, 0};
            for (int i = 0; i < mid; i++) {
                for (int j = 0; j < 2; j++) {
                    cur[j] = (1ll * cur[j] * B[j] + (s[i] - 'a' + 1)) % MOD[j];
                }
                
            }
            ada[f(cur[0], cur[1])] = true;
            string tmp;
            for (int i = mid; i < n; i++) {
                for (int j = 0; j < 2; j++) {
                    cur[j] = (1ll * cur[j] - 1ll * (s[i - mid] - 'a' + 1) * pw[mid - 1][j]) % MOD[j];
                    cur[j] = (1ll * cur[j] * B[j] + (s[i] - 'a' + 1)) % MOD[j];
                    if (cur[j] < 0) cur[j] += MOD[j];
                }
                if (ada.count(f(cur[0], cur[1]))) {
                    ok = true;
                    tmp = s.substr(i - mid + 1, mid);
                    break;
                }
                ada[f(cur[0], cur[1])] = true;
            }
            if (ok) {
                ret = tmp;
                piv = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ret;
    }
};