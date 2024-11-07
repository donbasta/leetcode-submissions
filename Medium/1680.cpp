class Solution {
public:
    const int MOD = 1e9 + 7;
    int dig[100001];

    int rec(int n) {
        if (n == 1) return 1;
        int prv = rec(n - 1);
        prv = (1ll * prv * (1 << dig[n])) % MOD;
        return (prv + n) % MOD;
    }

    int concatenatedBinary(int n) {
        dig[1] = 1;
        for (int i = 2; i <= n; i++) {
            dig[i] = dig[i / 2] + 1;
        }
        return rec(n);
    }
};