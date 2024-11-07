class Solution {
public:
    int countArrangement(int n) {
        vector<int> masks[n + 1];
        for (int i = 1; i < (1 << n); i++) {
            masks[__builtin_popcount(i)].push_back(i);
        }
        int dp[1 << n];
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (auto e : masks[i]) {
                dp[e] = 0;
                for (int j = 0; j < n; j++) {
                    if (!((e >> j) & 1)) continue;
                    if (!((j + 1) % i == 0) && !(i % (j + 1) == 0)) continue;
                    dp[e] += dp[e ^ (1 << j)];
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};