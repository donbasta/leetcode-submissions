class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n);
        for (int i = 0; i < n; i++) {
            pre[i] = (i ? pre[i - 1] : 0) + nums[i];
        }
        auto avg = [&](int a, int b) -> double {
            int sum = pre[b] - (a ? pre[a - 1] : 0);
            return (double)(sum) / (b - a + 1);
        };
        vector<vector<double>> dp(n, vector<double>(n + 1));
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][1] = avg(0, i);
            for (int j = 2; j <= i + 1; j++) {
                for (int kk = i - 1; kk >= j - 2; kk--) {
                    dp[i][j] = max(dp[i][j], dp[kk][j - 1] + avg(kk + 1, i));
                }
            }
        }
        double ans = 0;
        for (int i = 1; i <= k; i++) {
            ans = max(ans, dp[n - 1][i]);
        }
        return ans;
    }
};