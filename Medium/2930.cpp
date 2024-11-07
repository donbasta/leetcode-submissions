class Solution {
public:
    int stringCount(int n) {
        const int MOD = 1e9 + 7;
        
        auto fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };

        int X = fpow(26, n);
        int A = fpow(25, n);
        int B = (1ll * n * fpow(25, n - 1) + A) % MOD;
        int C = fpow(24, n);
        int D = (1ll * n * fpow(24, n - 1) + C) % MOD;
        int E = fpow(23, n);
        int F = 1ll * n * fpow(23, n - 1) % MOD;
        int ans = (1ll * X - A - A - B) % MOD;
        ans = (1ll * ans + C + D + D) % MOD;
        ans = (1ll * ans - E - F) % MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};