class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));

        int pref[n];
        pref[0] = stones[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i - 1] + stones[i];

        auto sum = [&](int l, int r) -> int {
            return pref[r] - (l ? pref[l - 1] : 0);
        };

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(sum(i, j - 1) - dp[i][j - 1], sum(i + 1, j) - dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};