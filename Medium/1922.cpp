class Solution {
public:
    int countGoodNumbers(long long n) {
        const int MOD = 1e9 + 7;

        auto fpow = [&](int x, long long y) -> int {
            int ret = 1;
            while (y) {
                if (y & 1) ret = (1ll * ret * x) % MOD;
                x = (1ll * x * x) % MOD;
                y >>= 1;
            }
            return ret;
        };

        int ans = 1;
        ans = (1ll * ans * fpow(5, (n + 1) / 2)) % MOD;
        ans = (1ll * ans * fpow(4, n / 2)) % MOD;
        return ans;
    }
};