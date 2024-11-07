class Solution {
public:
    int numOfWays(int n) {
        vector<vector<int>> dp(n, vector<int>(12));
        //orders:
        // ryr, 0
        // ryg, 1
        // rgr, 2
        // rgy, 3
        // yry, 4
        // yrg, 5
        // ygr, 6
        // ygy, 7
        // gry, 8
        // grg, 9
        // gyr, 10
        // gyg, 11
        vector<vector<int>> conn = {
            {4, 5, 7, 8, 9},
            {4, 6, 7, 8},
            {4, 5, 8, 9, 11},
            {5, 9, 10, 11},
            {0, 1, 2, 10, 11},
            {0, 2, 3, 10},
            {1, 8, 9, 11},
            {0, 1, 9, 10, 11},
            {0, 1, 2, 6},
            {0, 2, 3, 6, 7},
            {3, 4, 5, 7},
            {2, 3, 4, 6, 7}
        };
        const int MOD = 1e9 + 7;
        for (int i = 0; i < 12; i++) {
            dp[0][i] = 1;
        }
        const auto f = [&](int i, int j) -> int { return dp[i][j]; };
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 12; j++) {
                long long tmp = 0;
                for (auto k : conn[j]) {
                    tmp += f(i - 1, k);
                }
                dp[i][j] = tmp % MOD;
            }
        }
        int ans = 0;
        for (int i = 0; i < 12; i++) {
            ans = (1LL * ans + f(n - 1, i)) % MOD;
        }
        return ans;
    }
};