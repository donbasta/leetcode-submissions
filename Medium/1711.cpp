class Solution {
public:
    int countPairs(vector<int>& deli) {
        const int M = 1 << 20;
        int cnt[M + 1];
        memset(cnt, 0, sizeof(cnt));
        for (auto d : deli) cnt[d]++;
        const int MOD = 1e9 + 7;
        int ans = (1ll * cnt[0] * cnt[1]) % MOD;
        for (int i = 1; i <= 20; i++) {
            for (int j = 0; j < (1 << (i - 1)); j++) {
                ans = ((1ll * cnt[j] * cnt[(1 << i) - j]) + ans) % MOD;
            }
            ans = (1ll * cnt[1 << (i - 1)] * (cnt[1 << (i - 1)] - 1) / 2 + ans) % MOD;
        }
        ans = (1ll * cnt[1 << 20] * (cnt[1 << 20] - 1) / 2 + ans) % MOD;
        return ans;
    }
};