class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if (n == 1) return true;
        vector<int> sum(n);
        sum[0] = nums[0];
        for (int i = 1; i < n; i++) sum[i] = nums[i] + sum[i - 1];
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = true;
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                bool x = (sum[i + len - 1] - sum[i] >= m) && (dp[i + 1][i + len - 1]);
                bool y = (sum[i + len - 2] - (i ? sum[i - 1] : 0) >= m) && (dp[i][i + len - 2]);
                dp[i][i + len - 1] = (x || y);
            }
        }
        return dp[0][n - 1];
    }
};