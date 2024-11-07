class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2)));
        if (n <= 2) return true;
        for (int i = 0; i < n; i++) dp[i][i][0] = dp[i][i][1] = nums[i];
        for (int i = 0; i < n - 1; i++) dp[i][i + 1][0] = dp[i][i + 1][1] = max(nums[i], nums[i + 1]);
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                for (int p = 0; p < 2; p++) {
                    dp[i][i + len - 1][p] = max(
                        1ll * nums[i] + pre[i + len] - pre[i + 1] - dp[i + 1][i + len - 1][p ^ 1],
                        1ll * nums[i + len - 1] + pre[i + len - 1] - pre[i] - dp[i][i + len - 2][p ^ 1]
                    );
                }
            }
        }
        long long tot = pre[n];
        if (dp[0][n - 1][0] * 2 >= tot) return true;
        return false;
    }
};