class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        const int K = 800;
        const int MOD = 1e9 + 7;
        int val[K + 1];
        val[1] = 0;
        for (int i = 2; i <= K; i++) {
            val[i] = 1 + val[__builtin_popcount(i)];
        }

        int C[K + 1][K + 1];
        C[0][0] = C[1][0] = C[1][1] = 1;
        for (int i = 2; i <= K; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        int n = s.size();
        int c1 = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rem = n - 1 - i;
            if (s[i] == '1') {
                for (int j = 0; j <= rem; j++) {
                    if (val[c1 + j] <= k - 1) {
                        ans = (ans + C[rem][j]) % MOD;
                    }
                }
                c1++;
            }
        }
        return ans - 1;
    }
};