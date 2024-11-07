class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();

        // dp[i][x] = dp[i - 1][x] + dp[i - 1][x - 1] + ... + dp[i - 1][y]
        // nums[i - 1] - y >= nums[i] - x;
        // y <= nums[i - 1] - nums[i] + x;

        const int MOD = 1e9 + 7;
        const int M = 1000;
        vector<vector<int>> dp(n, vector<int>(M + 1)), pre(n, vector<int>(M + 1));
        for (int i = 0; i <= nums[0]; i++) dp[0][i] = 1;
        pre[0][0] = dp[0][0];
        for (int i = 1; i <= M; i++) pre[0][i] = (pre[0][i - 1] + dp[0][i]) % MOD;

        for (int i = 1; i < n; i++) {
            for (int x = 0; x <= nums[i]; x++) {
                int at = min(x, nums[i - 1] - nums[i] + x);
                dp[i][x] = (at >= 0 ? pre[i - 1][at] : 0);
            }
            pre[i][0] = dp[i][0];
            for (int x = 1; x <= M; x++) {
                pre[i][x] = (pre[i][x - 1] + dp[i][x]) % MOD;
            }
        }

        int ans = 0;
        for (int i = 0; i <= M; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }
        return ans;
    }
};