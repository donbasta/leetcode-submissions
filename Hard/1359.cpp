class Solution {
public:
    int fpow(int a, int b, int mod) {
        int ret = 1;
        while (b) {
            if (b & 1) ret = (1LL * ret * a) % mod;
            a = (1LL * a * a) % mod;
            b >>= 1;
        }
        return ret;
    }
    
    int countOrders(int n) {
        int a = 1;
        const int MOD = 1e9 + 7;
        for (int i = 1; i <= 2 * n; i++) {
            a = (1LL * a * i) % MOD;
        }
        int inv2 = fpow(2, MOD - 2, MOD);
        a = (1LL * a * fpow(inv2, n, MOD)) % MOD;
        return a;
    }
};