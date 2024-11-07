class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        int numss[n + 2];
        numss[0] = numss[n + 1] = 1;
        for (int i = 1; i <= n; i++) numss[i] = nums[i - 1];
        n += 2;
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int tmp = 0;
                for (int k = i + 1; k < i + len - 1; k++) {
                    tmp = max(tmp, dp[i][k] + dp[k][i + len - 1] + numss[i] * numss[k] * numss[i + len - 1]);
                }
                dp[i][i + len - 1] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};