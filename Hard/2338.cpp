class Solution {
public:
    int idealArrays(int n, int maxValue) {
        const int MOD = 1e9 + 7;
        int poly[2][15];
        memset(poly, 0, sizeof(poly));
        for (int i = 0; i <= 14; i++) {
            poly[1][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            int now = i & 1;
            int prv = now ^ 1;
            poly[now][0] = 0;
            for (int j = 1; j <= 14; j++) {
                poly[now][j] = (poly[prv][j] + poly[now][j - 1]) % MOD;
            }
        }
        int ans = 0;
        for (int i = 1; i <= maxValue; i++) {
            int tmp = 1;
            int ni = i;
            for (int j = 2; j * j <= ni; j++) {
                if (ni % j != 0) continue;
                int pw = 0;
                while (ni % j == 0) {
                    ni /= j, pw++;
                }
                tmp = (1ll * tmp * poly[n & 1][pw + 1]) % MOD;
            }
            if (ni > 1) {
                tmp = (1ll * tmp * poly[n & 1][2]) % MOD;
            }
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }
};