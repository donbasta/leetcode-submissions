class Solution {
public:
    int colorTheGrid(int m, int n) {
        int state = 1;
        for (int i = 0; i < m; i++) state *= 3;
        const int MOD = 1e9 + 7;

        int dp[state][n];
        memset(dp, 0, sizeof(dp));
        bool ok[state];
        memset(ok, false, sizeof(ok));
        string b3[state];

        auto check = [&](int mask) -> bool {
            vector<int> dig;
            while (mask) {
                if (!dig.empty() && ((mask % 3) == dig.back())) return false;
                dig.push_back(mask % 3);
                mask /= 3;
            }
            while (dig.size() < m) {
                if (!dig.empty() && dig.back() == 0) return false;
                dig.push_back(0);
            }
            return true;
        };

        auto base3 = [&](int mm) -> string {
            string ret;
            while (mm) {
                ret += (char)((mm % 3) + '0');
                mm /= 3;
            }
            while (ret.length() < m) ret += '0';
            return ret;
        };

        auto adj = [&](int m1, int m2) -> bool {
            for (int i = 0; i < m; i++) if (b3[m1][i] == b3[m2][i]) return false;
            return true;
        };

        for (int i = 0; i < state; i++) {
            ok[i] = check(i);
            if (ok[i]) {
                b3[i] = base3(i);
                dp[i][0] = 1;
            }
        }
        vector<int> nx[state];
        for (int i = 0; i < state; i++) {
            if (!ok[i]) continue;
            for (int j = 0; j < state; j++) {
                if (!ok[j]) continue;
                if (adj(i, j)) nx[i].push_back(j);
            }
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < state; j++) {
                if (!ok[j]) continue;
                for (auto c : nx[j]) {
                    dp[j][i] = (dp[j][i] + dp[c][i - 1]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < state; i++) {
            ans = (ans + dp[i][n - 1]) % MOD;
        }
        return ans;
    }
};