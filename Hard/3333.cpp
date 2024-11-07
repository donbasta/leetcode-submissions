class Solution {
public:
    int possibleStringCount(string word, int k) {
        int n = word.size();
        int last = 0;
        vector<int> parts;
        for (int i = 1; i < n; i++) {
            if (word[i] != word[i - 1]) {
                if (i - last > 1) {
                    parts.emplace_back(i - last - 1);
                }
                k--;
                last = i;
            }
        }
        if (n - last > 1) {
            parts.emplace_back(n - last - 1);
        }
        k--;
        const int MOD = 1e9 + 7;
        int ans = 1;
        for (auto p : parts) {
            ans = (1ll * ans * (p + 1)) % MOD;
        }
        if (k <= 0) {
            return ans;
        }

        int pre[k];
        for (int i = 0; i < k; i++) pre[i] = 1;
        for (auto p : parts) {
            for (int t = k - 1; t >= 0; t--) {
                pre[t] = (pre[t] - (t >= p + 1 ? pre[t - p - 1] : 0)) % MOD;
            }
            for (int t = 1; t < k; t++) {
                pre[t] = (pre[t] + pre[t - 1]) % MOD;
            }
        }
        ans = (ans - pre[k - 1]) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};