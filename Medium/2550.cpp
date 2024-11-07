class Solution {
public:
    int monkeyMove(int n) {
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
        int x = fpow(2, n);
        x = (x + MOD - 2) % MOD;
        return x;
    }
};