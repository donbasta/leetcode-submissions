class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const function<int(int, int)> fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };
        int MX = 1e5;
        int cnt[MX + 1], pre[MX + 2], suf[MX + 2];
        memset(cnt, 0, sizeof(cnt));
        pre[0] = 0;
        suf[MX + 1] = 0;
        for (auto e : nums) {
            cnt[e]++;
        }
        for (int i = 1; i <= MX; i++) {
            pre[i] = pre[i - 1] + cnt[i];
        }
        for (int i = MX; i >= 1; i--) {
            suf[i] = suf[i + 1] + cnt[i];
        }
        int ans = 0;
        for (int i = 1; i <= MX; i++) {
            if (cnt[i] == 0) continue;
            int tmp = 1ll * i * (fpow(2, cnt[i]) - 1) % MOD;
            tmp = 1ll * tmp * (fpow(2, pre[i - 1]) - fpow(2, suf[i + 1])) % MOD;
            if (tmp < 0) tmp += MOD;
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};