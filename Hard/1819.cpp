class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int MX = 2e5;
        int cnt[MX + 1], freq[MX + 1], dp[MX + 1], pd[MX + 1];
        memset(cnt, 0, sizeof(cnt));
        memset(freq, 0, sizeof(freq));
        for (auto e : nums) freq[e]++;
        for (int i = 1; i <= MX; i++) {
            for (int j = i; j <= MX; j += i) {
                cnt[i] += freq[j];
            }
        }
        const int MOD = 1e9 + 7;
        auto fpow = [&](int a, int b) {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        for (int i = 1; i <= MX; i++) {
            dp[i] = fpow(2, cnt[i]) - 1;
        }
        for (int i = MX; i >= 1; i--) {
            pd[i] = dp[i];
            for (int j = 2 * i; j <= MX; j += i) {
                pd[i] = (pd[i] - pd[j]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 1; i <= MX; i++) {
            if (pd[i] == 0) continue;
            ans++;
        }
        return ans;
    }
};