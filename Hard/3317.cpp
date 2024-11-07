class Solution {
public:
    int numberOfWays(int n, int x, int y) {
        int pw = 1;
        int ans = 0;

        const int MOD = 1e9 + 7;
        int C[1001][1001];
        memset(C, 0, sizeof(C));
        C[0][0] = 1;
        for (int i = 1; i <= 1000; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (1ll * C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        auto fpow = [&](int a, int b) -> int {
            int ret = 1;
            while (b) {
                if (b & 1) ret = (1ll * ret * a) % MOD;
                a = (1ll * a * a) % MOD;
                b >>= 1;
            }
            return ret;
        };

        for (int k = 1; k <= x; k++) {
            if (k > n) break;
            int st = C[x][k];
            pw = (1ll * pw * y) % MOD;
            int sc = pw;
            int inex = 0;
            for (int l = 0; l <= k; l++) {
                int A = C[k][l];
                int B = fpow((k - l), n);
                int tmp = (1ll * A * B) % MOD;
                if (l & 1) {
                    inex = (inex - tmp) % MOD;
                } else {
                    inex = (inex + tmp) % MOD;
                }
            }
            int lmao = (1ll * st * sc) % MOD;
            lmao = (1ll * lmao * inex) % MOD;
            ans = (1ll * ans + lmao) % MOD;
        }
        ans %= MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};