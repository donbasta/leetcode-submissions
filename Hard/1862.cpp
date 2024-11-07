class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int MX = 1e5;
        vector<int> cnt(MX + 1), pre(MX + 1);
        for (auto e : nums) cnt[e]++;
        for (int i = 1; i <= MX; i++) pre[i] = pre[i - 1] + cnt[i];
        int ans = 0;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= MX; i++) {
            if (cnt[i] == 0) continue;
            int tmp = 0;
            int cur = 1;
            while (cur * i <= MX) {
                int atas = (cur + 1) * i - 1;
                int bawah = cur * i - 1;
                tmp = (1ll * cur * (pre[min(atas, MX)] - pre[bawah]) + tmp) % MOD;
                cur++;
            }
            tmp = 1ll * tmp * cnt[i] % MOD;
            ans = (ans + tmp) % MOD;
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};