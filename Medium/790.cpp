class Solution {
public:
    int numTilings(int n) {
        // p_n = p_(n-1) + p_(n - 2) + 2 * p_(n - 3) + 2 * p_(n - 4) + ...;
        int p[n + 10];
        p[0] = 1;
        p[1] = 1;
        p[2] = 2;
        const int MOD = 1e9 + 7;
        for (int i = 3; i <= n; i++) {
            p[i] = p[i - 1] % MOD;
            p[i] = (p[i] + p[i - 2]) % MOD;
            for (int j = i - 3; j >= 0; j--) {
                p[i] = (1ll * p[i] + p[j] * 2) % MOD;
            }
        }
        return p[n];
    }
};