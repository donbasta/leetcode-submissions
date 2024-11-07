class Solution {
public:
    int countSteppingNumbers(string low, string high) {
        const int MOD = 1e9 + 7;

        vector<int> dp(101);
        vector<vector<int>> dpp(10, vector<int>(101));

        dp[1] = 10;
        for (int i = 0; i <= 9; i++) {
            dpp[i][1] = 1;
        }

        for (int i = 2; i <= 100; i++) {
            for (int j = 0; j <= 9; j++) {
                if (j >= 1) dpp[j][i] = (dpp[j][i] + dpp[j - 1][i - 1]) % MOD;
                if (j <= 8) dpp[j][i] = (dpp[j][i] + dpp[j + 1][i - 1]) % MOD;
                dp[i] = (dp[i] + dpp[j][i]) % MOD;
            }
        }
        
        auto ok = [&](const string& s) -> bool {
            int n = s.length();
            bool ok = true;
            for (int i = 1; i < n; i++) {
                ok &= (abs(s[i] - s[i - 1]) == 1);
            }
            return ok;
        };

        auto solve = [&](const string& s) -> int {
            int n = s.length();
            if (n == 1) return stoi(s);
            int ret = 0;
            for (int i = 1; i < n; i++) {
                ret = (1ll * ret + dp[i] - dpp[0][i]) % MOD;
            }
            for (int i = 0; i < n; i++) {
                int cur = s[i] - '0';
                if (i == 0) {
                    for (int j = 1; j < cur; j++) {
                        if (j >= 1) ret = (1ll * ret + dpp[j - 1][n - 1]) % MOD;
                        if (j <= 8) ret = (1ll * ret + dpp[j + 1][n - 1]) % MOD;
                    }
                } else {
                    int prv = s[i - 1] - '0';
                    if (prv - 1 >= 0 && prv - 1 < cur) {
                        if (n - 1 - i != 0) {
                            if (prv - 1 >= 1) ret = (1ll * ret + dpp[prv - 2][n - 1 - i]) % MOD;
                            if (prv - 1 <= 8) ret = (1ll * ret + dpp[prv][n - 1 - i]) % MOD;
                        } else {
                            ret = (ret + 1) % MOD;
                        }
                    }
                    if (prv + 1 <= 9 && prv + 1 < cur) {
                        if (n - 1 - i != 0) {
                            if (prv + 1 >= 1) ret = (1ll * ret + dpp[prv][n - 1 - i]) % MOD;
                            if (prv + 1 <= 8) ret = (1ll * ret + dpp[prv + 2][n - 1 - i]) % MOD;
                        } else {
                            ret = (ret + 1) % MOD;
                        }
                    }
                    if (abs(cur - prv) != 1) break;
                }
            }
            ret += ok(s);
            return ret;
        };

        // cout << solve(high) << ' ' << solve(low) << '\n';

        int ans = (solve(high) - solve(low)) % MOD;
        if (ok(low)) ans++;
        ans %= MOD;
        if (ans < 0) ans += MOD;
        return ans;
    }
};