class Solution {
public:
    int countBalancedPermutations(string num) {
        int n = num.length();
        const int MOD = 1e9 + 7;
        const int B = 800;
        vector<vector<int>> dp(n + 1, vector<int>(2 * B + 5));
        vector<int> cnt(10);
        for (auto c : num) cnt[c - '0']++;

        int C[81][81];
        C[0][0] = C[1][0] = C[1][1] = 1;
        for (int i = 2; i <= 80; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        int cur = 0, tot = 0;
        dp[0][B] = 1;
        for (int i = 0; i < 10; i++) {
            cur += cnt[i];
            tot += cnt[i] * i;
            vector<vector<int>> pd(cur + 1, vector<int>(2 * B + 5));
            for (int x = 0; x <= cur; x++) {
                for (int j = -tot; j <= tot; j++) {
                    for (int k = 0; k <= cnt[i]; k++) {
                        if (k > x) break;
                        if (cnt[i] - k > cur - x) continue;
                        if (j - i * (2 * k - cnt[i]) < -B) break;
                        if (j - i * (2 * k - cnt[i]) > B) continue;
                        int add = dp[x - k][j - i * (2 * k - cnt[i]) + B];
                        add = (1ll * add * C[x][k]) % MOD;
                        add = (1ll * add * C[cur - x][cnt[i] - k]) % MOD;
                        pd[x][j + B] = (pd[x][j + B] + add) % MOD;
                    }
                }
            }
            dp.swap(pd);
        }

        return dp[n / 2][B];
    }
};